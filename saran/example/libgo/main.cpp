#include <iostream>

#include <libgo/libgo.h>
#include <atomic>

std::atomic<int> g_value{0};
static constexpr int co_count = 100000;
static constexpr int switch_per_co = 10;

void fun() {
    for (int i = 0; i < switch_per_co; ++i) {
        g_value++;
        std::cout << "fun " << g_value << std::endl;
        co_yield;
    }
}

int main(int argc, char **argv) {
//    g_Scheduler.GetOptions().stack_size = 2048;
    for (int i = 0; i < co_count; ++i) {
        go fun;
    }
    std::cout << "go start" << std::endl;
//    while (!g_Scheduler.IsEmpty()) {
//        g_Scheduler.Run();
//    }
    std::cout << "go end" << std::endl;
    return 0;
}
