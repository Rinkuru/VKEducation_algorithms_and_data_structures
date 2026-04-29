#include <gtest/gtest.h>
#include "src.cpp"

TEST(HW6, test_longestIncreasingSubarray) {
  EXPECT_EQ(longestIncreasingSubarray(std::vector<int>({3,2,8,9,5,10})), 3);
  EXPECT_EQ(longestIncreasingSubarray(std::vector<int>({1,2,7,9,0,10})), 4);
  EXPECT_EQ(longestIncreasingSubarray(std::vector<int>({8,8,8,8})), 1);
  EXPECT_EQ(longestIncreasingSubarray(std::vector<int>({})), 0);
  EXPECT_EQ(longestIncreasingSubarray(std::vector<int>({5})), 1);
  EXPECT_EQ(longestIncreasingSubarray(std::vector<int>({5,4,3,2,1})), 1);
}

TEST(HW6, test_pascalTriangle) {
  EXPECT_EQ(pascalTriangle(0), std::vector<std::vector<int>>({}));
  EXPECT_EQ(pascalTriangle(1), std::vector<std::vector<int>>({{1}}));
  EXPECT_EQ(
    pascalTriangle(5),
    std::vector<std::vector<int>>({
      {1},
      {1, 1},
      {1, 2, 1},
      {1, 3, 3, 1},
      {1, 4, 6, 4, 1}
    })
  );
}

TEST(HW6, test_coinChange) {
  EXPECT_EQ(coinChange(std::vector<int>({1,2,5}), 11), 3);
  EXPECT_EQ(coinChange(std::vector<int>({2}), 3), -1);
  EXPECT_EQ(coinChange(std::vector<int>({1,3,4}), 6), 2);
  EXPECT_EQ(coinChange(std::vector<int>({1,2,5}), 0), 0);
  EXPECT_EQ(coinChange(std::vector<int>({}), 7), -1);
}

TEST(HW6, test_longestPalindrome) {
  EXPECT_EQ(longestPalindrome(""), "");
  EXPECT_EQ(longestPalindrome("a"), "a");
  EXPECT_EQ(longestPalindrome("cbbd"), "bb");
  EXPECT_EQ(longestPalindrome("forgeeksskeegfor"), "geeksskeeg");
  EXPECT_EQ(longestPalindrome("aaaa"), "aaaa");
}
