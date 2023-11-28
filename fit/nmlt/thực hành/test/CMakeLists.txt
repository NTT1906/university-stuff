cmake_minimum_required(VERSION 3.25)
project(test)

set(CMAKE_CXX_STANDARD 17)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

set(test main.cpp)

add_executable(test main.cpp)