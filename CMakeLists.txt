cmake_minimum_required(VERSION 3.14)

project(range-cpp
    VERSION 0.1
    DESCRIPTION "C++ implementation of Python range function"
    HOMEPAGE_URL https://github.com/jasz0008/range-cpp
    LANGUAGES CXX
)

# Library
add_library(range-cpp)
target_compile_options(range-cpp
    PRIVATE
        $<$<IN_LIST:$<CXX_COMPILER_ID>,"Clang;GNU">:
            -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Werror
        >
        $<$<CXX_COMPILER_ID:Clang>:-Weverything -Weffc++>
        $<$<CXX_COMPILER_ID:MSVC>:/Wall /permissive /WX>
)
#target_include_directories(range-cpp INTERFACE include/range-cpp)
# TODO: Export headers
#target_link_options(range-cpp
#    PRIVATE
#        $<$<CXX_COMPILER_ID:MSVC>:/Wall /permissive /WX>
#)
target_sources(range-cpp PRIVATE src/range.cpp)
set_target_properties(range-cpp PROPERTIES
    CXX_EXTENSIONS NO
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
)
install(
    TARGETS range-cpp
    EXPORT range-cpp
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
install(EXPORT range-cpp DESTINATION lib/cmake/range-cpp-${PROJECT_VERSION})

# Get Google Test
file(READ googletest.sha512 googletest_sha512)
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.8.1.tar.gz
    #URL_HASH SHA512=${googletest_sha512}
)
FetchContent_MakeAvailable(googletest)
#add_subdirectory(
#    "${googletest_SOURCE_DIR}"
#    "${googletest_BINARY_DIR}"
#    EXCLUDE_FROM_ALL
#)

# Tests
#add_executable(range-cpp-tests)
#target_compile_options(range-cpp-tests
#    PRIVATE
#        $<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:
#            -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic
#        >
#        $<$<CXX_COMPILER_ID:Clang>:-Weverything -Weffc++>
#        $<$<CXX_COMPILER_ID:MSVC>:/Wall /permissive /WX>
#)
#target_sources(range-cpp-tests PRIVATE tests.cpp)
#target_link_libraries(range-cpp-tests
#    PRIVATE
#        range-cpp
#        gtest_main
#)
#target_link_options(range-cpp-tests
#    PRIVATE
#        $<$<CXX_COMPILER_ID:MSVC>:/Wall /permissive /WX>
#)
#set_target_properties(range-cpp-tests PROPERTIES
#    CXX_EXTENSIONS NO
#    CXX_STANDARD 11
#    CXX_STANDARD_REQUIRED YES
#)
#install(
#    TARGETS range-cpp-tests
#    RUNTIME
#        COMPONENT Tests
#        DESTINATION bin
#)
