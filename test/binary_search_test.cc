#include <gtest/gtest.h>

extern "C" {
#include "../src/binary_search.h"
}

TEST(HelloTest, BasicAssertions1) {

    int arr[] = {1, 5, 9};
    int target = 5;
    int pos = binary_search(arr, 3, target);

    // Expect equality.
    EXPECT_EQ(pos, 1);
}

TEST(HelloTest, BasicAssertions2) {

    int arr[] = {1, 5, 9};
    int target = 4;
    int pos = binary_search(arr, 3, target);

    // Expect equality.
    EXPECT_EQ(pos, -1);
}



TEST(HelloTest, BasicAssertions3) {

    int arr[] = {1, 5, 9};
    int target = 10;
    int pos = binary_search(arr, 3, target);

    // Expect equality.
    EXPECT_EQ(pos, -1);
}

TEST(HelloTest, BasicAssertions4) {

    int arr[] = {1, 5, };
    int target = 1;
    int pos = binary_search(arr, 3, target);

    // Expect equality.
    EXPECT_EQ(pos, -1);
}
