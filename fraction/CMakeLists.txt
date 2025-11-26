cmake_minimum_required(VERSION 3.28)
project(fraction)

set(CMAKE_CXX_STANDARD 17)

add_executable(fraction main.cpp
        fraction.cpp
        fraction.h)
