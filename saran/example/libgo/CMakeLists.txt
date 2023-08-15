cmake_minimum_required (VERSION 2.8)

PROJECT(libgoTest)

set(CXX_FLAGS
        -g
        -Wall
        -std=c++11
        )

add_executable(libgoTest main.cpp)
target_link_libraries(libgoTest /usr/local/lib/liblibgo.a)