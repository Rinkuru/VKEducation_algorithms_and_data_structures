#include <climits>
#include <gtest/gtest.h>
#include "src.cpp"

TEST(HW3, test_binarySearchSqrt) {
  EXPECT_EQ(binarySearchSqrt(0), 0);
  EXPECT_EQ(binarySearchSqrt(1), 1);
  EXPECT_EQ(binarySearchSqrt(16), 4);
  EXPECT_EQ(binarySearchSqrt(17), 4);
  EXPECT_EQ(binarySearchSqrt(INT_MAX), 46340);
}

TEST(HW3, test_copyTime) {
  EXPECT_EQ(copyTime(1, 3, 5), 3);
  EXPECT_EQ(copyTime(4, 2, 2), 6);
  EXPECT_EQ(copyTime(5, 1, 2), 4);
  EXPECT_EQ(copyTime(10, 1, 100), 10);
}

TEST(HW3, test_feedAnimals) {
  EXPECT_EQ(feedAnimals(std::vector<int>({3, 4, 7}), std::vector<int>({8, 1, 2})), 1);
  EXPECT_EQ(feedAnimals(std::vector<int>({3, 8, 1, 4}), std::vector<int>({1, 1, 2})), 1);
  EXPECT_EQ(feedAnimals(std::vector<int>({1, 2, 2}), std::vector<int>({7, 1})), 2);
  EXPECT_EQ(feedAnimals(std::vector<int>({8, 2, 3, 2}), std::vector<int>({1, 4, 3, 8})), 3);
  EXPECT_EQ(feedAnimals(std::vector<int>({}), std::vector<int>({1, 2, 3})), 0);
}

TEST(HW3, test_extraLetter) {
  EXPECT_EQ(extraLetter("uio", "oeiu"), "e");
  EXPECT_EQ(extraLetter("fe", "efo"), "o");
  EXPECT_EQ(extraLetter("bbb", "bbbb"), "b");
  EXPECT_EQ(extraLetter("ab", "ab"), "");
}

TEST(HW3, test_twoSum) {
  EXPECT_EQ(twoSum(std::vector<int>({2, 7, 11, 15}), 9), std::vector<int>({0, 1}));
  EXPECT_EQ(twoSum(std::vector<int>({3, 3}), 6), std::vector<int>({0, 1}));
  EXPECT_EQ(twoSum(std::vector<int>({3, 2, 4}), 6), std::vector<int>({1, 2}));
  EXPECT_EQ(twoSum(std::vector<int>({1, 2, 3}), 7), std::vector<int>({}));
}
