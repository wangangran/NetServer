#include <iostream>
#include <experimental/coroutine>
#include <future>

std::future<int> asyncTask() {
    return std::async([] {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return 42;
    });
}

std::experimental::coroutine_handle<> coroutine;

std::experimental::suspend_never final_awaiter() noexcept { return {}; }

template <typename Promise>
struct MyFuture {
    struct promise_type {
        Promise promise;

        auto get_return_object() {
            return MyFuture{std::experimental::coroutine_handle<promise_type>::from_promise(*this)};
        }
        auto initial_suspend() { return std::experimental::suspend_always{}; }
        auto final_suspend() noexcept { return final_awaiter(); }
        void unhandled_exception() { std::terminate(); }
    };

    using handle_type = std::experimental::coroutine_handle<promise_type>;
    handle_type coro;

    MyFuture(handle_type h) : coro(h) {}

    ~MyFuture() {
        if (coro)
            coro.destroy();
    }
};

MyFuture<int> asyncTaskCoroutine() {
    co_return co_await asyncTask();
}

int main() {
    coroutine = asyncTaskCoroutine().coro;
    while (!coroutine.done()) {
        coroutine.resume();
    }
    std::cout << "Coroutine result: " << coroutine.promise().promise.get_return_object().promise.value << std::endl;
    coroutine.destroy();
    return 0;
}