cmake_minimum_required(VERSION 3.8)
project(TSDB)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(TSDB ${SOURCE_FILES})