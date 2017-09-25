cmake_minimum_required(VERSION 3.8)
project(TSDB)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp
        core)
add_executable(TSDB ${SOURCE_FILES})