cmake_minimum_required (VERSION 2.8)

project (saran)

set(CXX_FLAGS
        -g
        -Wall
        -std=c++20
        -pthread
        )

string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

set(CMAKE_CXX_FLAGS_DEGUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

if(${CMAKE_BUILD_TYPE} MATCHES "Release")
    set(BuildType "Release")
else()
    set(BuildType "Debug")
endif()

add_executable(reflection main.cpp)