#include <iostream>
#include <coroutine>

struct MyCoroutine {
    struct promise_type {
        int result;

        MyCoroutine get_return_object() {
            return MyCoroutine(std::coroutine_handle<promise_type>::from_promise(*this));
        }

        std::suspend_always initial_suspend() {
            return {};
        }

        std::suspend_always final_suspend() noexcept {
            return {};
        }

        void return_value(int value) {
            result = value;
        }

        void unhandled_exception() {
            std::terminate();
        }
    };

    std::coroutine_handle<promise_type> coro;

    explicit MyCoroutine(std::coroutine_handle<promise_type> handle) : coro(handle) {}

    ~MyCoroutine() {
        if (coro) {
            coro.destroy();
        }
    }

    void resume() {
        coro.resume();
    }

    bool done() {
        return coro.done();
    }

    int getResult() {
        return coro.promise().result;
    }
};

MyCoroutine myCoroutine() {
    co_return 42;
}

int main() {
    MyCoroutine coro = myCoroutine();
    coro.resume();

    if (!coro.done()) {
        coro.resume();
    }

    std::cout << "Result: " << coro.getResult() << std::endl;

    return 0;
}