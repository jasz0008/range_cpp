add_library(range_cpp)
target_compile_options(range_cpp
    PRIVATE
        $<$<IN_LIST:$<CXX_COMPILER_ID>,"Clang;GNU">:
            -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Werror
        >
        $<$<CXX_COMPILER_ID:Clang>:-Weverything -Weffc++>
        $<$<CXX_COMPILER_ID:MSVC>:/Wall /permissive- /WX>
)
target_include_directories(range_cpp PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
include(GenerateExportHeader)
generate_export_header(range_cpp
    EXPORT_FILE_NAME range_cpp_exports.hxx
)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.13)
    target_link_options(range_cpp
        PRIVATE
            $<$<CXX_COMPILER_ID:MSVC>:/Wall /permissive /WX>
    )
else()
    target_link_libraries(range_cpp
        PRIVATE
            $<$<CXX_COMPILER_ID:MSVC>:/Wall /permissive /WX>
    )
endif()
target_sources(range_cpp PRIVATE src/range.cpp)
set_target_properties(range_cpp PROPERTIES
    #CXX_CLANG_TIDY
    #CXX_CPPCHECK --inline-suppr --verbose --template="{file}|{line}|{severity}{id}|{message}"
    #--library=std --language=c++ --enable=all --inconclusive
    #CXX_CPPLINT 
    CXX_EXTENSIONS NO
    #CXX_INCLUDE_WHAT_YOU_USE
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    DEBUG_POSTFIX d
    LINK_WHAT_YOU_USE YES
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
install(
    FILES
        include/range_cpp.hpp
        ${PROJECT_BINARY_DIR}/range_cpp_exports.hxx
    DESTINATION
        include/range_cpp
)
install(EXPORT range_cpp DESTINATION lib/cmake/range_cpp-${PROJECT_VERSION})