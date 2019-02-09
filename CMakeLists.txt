cmake_minimum_required(VERSION 3.14)

project(range_cpp
    VERSION 0.1
    DESCRIPTION "C++ implementation of Python range function"
    HOMEPAGE_URL https://github.com/jasz0008/range_cpp
    LANGUAGES CXX
)

# Library
add_library(range_cpp)
target_compile_options(range_cpp
    PRIVATE
        $<$<IN_LIST:$<CXX_COMPILER_ID>,"Clang;GNU">:
            -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Werror
        >
        $<$<CXX_COMPILER_ID:Clang>:-Weverything -Weffc++>
        $<$<CXX_COMPILER_ID:MSVC>:/Wall /permissive /WX>
)
#target_include_directories(range_cpp INTERFACE include/range_cpp)
# TODO: Export headers
#target_link_options(range_cpp
#    PRIVATE
#        $<$<CXX_COMPILER_ID:MSVC>:/Wall /permissive /WX>
#)
target_sources(range_cpp PRIVATE src/range.cpp)
set_target_properties(range_cpp PROPERTIES
    CXX_EXTENSIONS NO
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    DEBUG_POSTFIX d
    SOVERSION ${PROJECT_VERSION}
    VERSION ${PROJECT_VERSION}
)
install(
    TARGETS range_cpp
    EXPORT range_cpp
    ARCHIVE
        COMPONENT Library
        DESTINATION lib
    LIBRARY
        COMPONENT Library
        DESTINATION lib
    PUBLIC_HEADER
        COMPONENT Library
        DESTINATION include
    RUNTIME
        COMPONENT Library
        DESTINATION bin
)
install(EXPORT range_cpp DESTINATION lib/cmake/range_cpp-${PROJECT_VERSION})

# Prevent overriding the parent project's compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Get Google Test
file(STRINGS googletest.sha512 googletest_sha512)
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.8.1.tar.gz
    URL_HASH SHA512=${googletest_sha512}
)
FetchContent_MakeAvailable(googletest)

# Tests
add_executable(range_cpp_tests)
target_compile_options(range_cpp_tests
    PRIVATE
        $<$<IN_LIST:$<CXX_COMPILER_ID>,"Clang;GNU">:
            -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Werror
        >
        $<$<CXX_COMPILER_ID:Clang>:-Weverything -Weffc++>
        $<$<CXX_COMPILER_ID:MSVC>:/Wall /permissive /WX>
)
target_sources(range_cpp_tests PRIVATE src/tests.cpp)
target_link_libraries(range_cpp_tests
    PRIVATE
        range_cpp
        gtest
)
target_link_options(range_cpp_tests
    PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:/Wall /permissive /WX>
)
set_target_properties(range_cpp_tests PROPERTIES
    CXX_EXTENSIONS NO
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    DEBUG_POSTFIX d
    SOVERSION ${PROJECT_VERSION}
    VERSION ${PROJECT_VERSION}
)
install(
    TARGETS range_cpp_tests
    RUNTIME
        COMPONENT Tests
        DESTINATION bin
)

# CTest test discovery
include(GoogleTest)
gtest_discover_tests(range_cpp_tests)
include(CTest)
