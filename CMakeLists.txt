cmake_minimum_required(VERSION 3.3)
project(cwi)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c cwi.c cwi.h)
add_executable(cwi ${SOURCE_FILES})