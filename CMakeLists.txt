cmake_minimum_required(VERSION 3.16)
project(cpu)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpu src/main.cpp src/string.h)
