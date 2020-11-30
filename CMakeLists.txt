cmake_minimum_required(VERSION 3.16.5)
project(hw1)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -Werror -pedantic-errors -DNDEBUG")

add_executable(hw1 main.cpp)