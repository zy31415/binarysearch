cmake_minimum_required(VERSION 3.19)
project(bs)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(src)
add_subdirectory(test)

enable_testing()

#add_executable(bs src/binary_search.c src/binary_search.h)
#
#add_executable(bslarge binary_search_large_file.c)
#
#set_target_properties(bslarge bs
#        PROPERTIES RUNTIME_OUTPUT_DIRECTORY bin)

#add_library(binary_search_lib SHARED
#        src/binary_search.c
#        )



