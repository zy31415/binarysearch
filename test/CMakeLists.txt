include_directories(${PROJECT_SOURCE_DIR}/src)


include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)


add_executable(
        binary_search_test.bin
        binary_search_test.cc
)

target_link_libraries(
        binary_search_test.bin
        binary_search
        gtest_main
)

add_executable(
        binary_search_str_test.bin
        binary_search_str_test.cc
)

target_link_libraries(
        binary_search_str_test.bin
        binary_search
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(binary_search_str_test.bin)