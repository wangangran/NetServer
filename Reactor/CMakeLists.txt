cmake_minimum_required (VERSION 2.8)

project (sunwar)

set(CXX_FLAGS
 -g
 -Wall
 -std=c++11
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

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/${BuildType})

include_directories("${PROJECT_SOURCE_DIR}/src")

add_subdirectory("${PROJECT_SOURCE_DIR}/src/base")
add_subdirectory("${PROJECT_SOURCE_DIR}/src/net")


#example
add_subdirectory("${PROJECT_SOURCE_DIR}/example/echo")
add_subdirectory("${PROJECT_SOURCE_DIR}/example/log")