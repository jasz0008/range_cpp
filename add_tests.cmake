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

add_executable(range_cpp_tests)
set(RANGE_CPP_COVERAGE OFF CACHE BOOL "Enable coverage checks")
if (RANGE_CPP_COVERAGE)
    target_compile_options(range_cpp_tests PRIVATE --coverage)
    target_link_options(range_cpp_tests PRIVATE --coverage)
endif()
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
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.13)
    target_link_options(range_cpp_tests
        PRIVATE
            $<$<CXX_COMPILER_ID:MSVC>:/Wall /permissive /WX>
    )
else()
    target_link_libraries(range_cpp_tests
        PRIVATE
            $<$<CXX_COMPILER_ID:MSVC>:/Wall /permissive /WX>
    )
endif()
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