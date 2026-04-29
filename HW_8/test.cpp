#include <gtest/gtest.h>
#include "src.cpp"

TEST(HW8, test_maxSubarraySum) {
  EXPECT_EQ(maxSubarraySum(std::vector<int>({1,2,3,4,5}), 2), 9);
  EXPECT_EQ(maxSubarraySum(std::vector<int>({4,-1,2,1,-5,4}), 3), 5);
  EXPECT_EQ(maxSubarraySum(std::vector<int>({-5,-2,-8}), 1), -2);
  EXPECT_EQ(maxSubarraySum(std::vector<int>({3,1,4}), 3), 8);
}

TEST(HW8, test_subarraySumEqualsK) {
  EXPECT_EQ(subarraySumEqualsK(std::vector<int>({1,1,1}), 2), 2);
  EXPECT_EQ(subarraySumEqualsK(std::vector<int>({1,2,3}), 3), 2);
  EXPECT_EQ(subarraySumEqualsK(std::vector<int>({1,-1,0}), 0), 3);
  EXPECT_EQ(subarraySumEqualsK(std::vector<int>({3,8,6,9,2,1,4}), 11), 2);
}

TEST(HW8, test_findMaxLengthEqualZeroOne) {
  EXPECT_EQ(findMaxLengthEqualZeroOne(std::vector<int>({})), 0);
  EXPECT_EQ(findMaxLengthEqualZeroOne(std::vector<int>({0,0,0})), 0);
  EXPECT_EQ(findMaxLengthEqualZeroOne(std::vector<int>({0,1})), 2);
  EXPECT_EQ(findMaxLengthEqualZeroOne(std::vector<int>({0,1,0,0,1})), 4);
  EXPECT_EQ(findMaxLengthEqualZeroOne(std::vector<int>({0,1,0,1,1,0,0})), 6);
}

TEST(HW8, test_pivotIndex) {
  EXPECT_EQ(pivotIndex(std::vector<int>({1,7,3,6,5,6})), 3);
  EXPECT_EQ(pivotIndex(std::vector<int>({1,2,3})), -1);
  EXPECT_EQ(pivotIndex(std::vector<int>({2,1,-1})), 0);
  EXPECT_EQ(pivotIndex(std::vector<int>({-1,-1,0,1,1,0})), 5);
}

TEST(HW8, test_isBalancedBrackets) {
  EXPECT_TRUE(isBalancedBrackets(""));
  EXPECT_TRUE(isBalancedBrackets("()"));
  EXPECT_TRUE(isBalancedBrackets("(()())"));
  EXPECT_FALSE(isBalancedBrackets(")("));
  EXPECT_FALSE(isBalancedBrackets("(()"));
  EXPECT_FALSE(isBalancedBrackets("())("));
}
