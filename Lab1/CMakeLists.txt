cmake_minimum_required(VERSION 3.20)
project(lab1_tepzoid)

set(CMAKE_CXX_STANDARD 14)

include_directories(Lab1)

add_executable(lab1_tepzoid
        Lab1/Header.h
        Lab1/Lab1.cpp)
