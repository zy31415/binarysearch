#include <gtest/gtest.h>

extern "C" {
#include "../src/binary_search.h"
}

TEST(BinarySearchString, BasicAssertions1) {

    const char *arr[] = {"aa", "csbd", "ddsb"};
    char target[] = "csbd";
    int pos = binary_search_str(arr, 3, target);

    // Expect equality.
    EXPECT_EQ(pos, 1);
}


TEST(BinarySearchString, BasicAssertions2) {

    const char *arr[] = {"aa", "csbd", "ddsb"};
    char target[] = "b";
    int pos = binary_search_str(arr, 3, target);

    // Expect equality.
    EXPECT_EQ(pos, -1);
}

TEST(BinarySearchString, BasicAssertions3) {

    const char *arr[] = {"aa", "ab", "ac"};
    char target[] = "ac";
    int pos = binary_search_str(arr, 3, target);

    // Expect equality.
    EXPECT_EQ(pos, 2);
}

