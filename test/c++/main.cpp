//
// Created by Administrator on 2023/8/9.
//
#include <iostream>
#include <string>

#include "reflection.h"

template<typename T, typename... Args>
void fun(const T &t, const Args&... args) {
    std::cout << sizeof(T) << std::endl;
    std::cout << sizeof(t) << std::endl;
    std::cout << sizeof...(Args) << std::endl;
    std::cout << sizeof...(args) << std::endl;
}

template<typename T, typename... Args>
size_t fun1() {
    std::cout << sizeof(T) << std::endl;
    std::cout << sizeof...(Args) << std::endl;
    return sizeof...(Args);
}

struct TypeA {
    int a;
    float b;
    char c;
    std::string str;
};

template<typename T>
void print(const T &t) {
    std::cout << "end " << t << std::endl;
}

template<typename T, typename... Args>
void print(const T &t, const Args&... args) {
    std::cout << t << std::endl;
    print(args...);
}

int main(int argc, char *argv[]) {
    TypeA objA{.a = 1, .b = 2.0, .c = 'a', .str = "hello war"};
    int num = MemberCountImpl<TypeA>();
    std::cout << num << " " << sizeof(TypeA) << std::endl;

    int a = 0;
    float b = 1.0;
    double c = 2.0;
    std::string d = "hello";


    TypeA objB = TypeA{{1}, {2.0}, {'a'}, {"hello"}};
    std::cout << fun1<TypeA>() << objB.str << std::endl;

    auto printBind = [&] (auto &&...args) {
        print(args...);
    };

    auto &&[a1, a2, a3, a4] = objB; //{{std::string("hello")}, {9}, {3}};
    // std::cout << a1 << " " << a2 << " " << a3 << " " << a4 << std::endl;

    printBind(a1, a2, a3, a4);
    return 0;
}

