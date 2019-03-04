# CMake version 3.5.1 is provided in Ubuntu 16.04 LTS Xenial Xerus
cmake_minimum_required(VERSION 3.5.1) 

project(range_cpp 
    LANGUAGES CXX
    VERSION 0.1
)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.9.6)
    set(PROJECT_DESCRIPTION "C++ implementation of Python range function")
endif()
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.12.4)
    set(PROJECT_HOMEPAGE_URL https://github.com/jasz0008/range_cpp)
endif()

# Library
include(add_library.cmake)

# Tests
option(RANGE_CPP_BUILD_TESTS "Build range_cpp tests" ON)
if(RANGE_CPP_BUILD_TESTS)
    include(add_tests.cmake)
endif()