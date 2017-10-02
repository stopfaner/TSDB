cmake_minimum_required(VERSION 3.8)
project(TSDB)

set(CMAKE_CXX_STANDARD 11)

message(STATUS "start running cmake...")

find_package(Boost 1.65.0 COMPONENTS system filesystem REQUIRED)

if(Boost_FOUND)

    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})

endif()


set(SOURCE_FILES main.cpp
        core)
add_executable(TSDB ${SOURCE_FILES})

if(Boost_FOUND)

    target_link_libraries(TSDB ${Boost_LIBRARIES})

endif()