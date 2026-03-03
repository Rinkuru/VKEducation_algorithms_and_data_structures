#include <gtest/gtest.h>
#include "src.cpp"

#define k 3
TEST(HW1, test_reverseMas) {
  std::vector<int> mas = {0,1,2,3,4,5,6,7};
  int n = mas.size()-1;
  reverseMas(mas, k);
  printMas(mas);
  EXPECT_EQ(mas, std::vector<int>({5,6,7,0,1,2,3,4}));
}

TEST(HW1, test_mergeMas) {
  std::vector<int> mas1 = {1,3,5,6,7,9,10};
  std::vector<int> mas2 = {2,4,8};
  std::vector<int> mas3 = mergeMas(mas1, mas2);
  printMas(mas3);
  EXPECT_EQ(mas3, std::vector<int>({1,2,3,4,5,6,7,8,9,10}));
}

TEST(HW1, test_mergeMas2) {
  std::vector<int> mas1 = {1,3,5,6,7,9,10,0,0,0,0};
  std::vector<int> mas2 = {2,4,8,11};
  std::vector<int> &mas3 = mergeMas2(mas1, mas2);
  printMas(mas3);
  EXPECT_EQ(mas3, std::vector<int>({1,2,3,4,5,6,7,8,9,10,11}));
}

TEST(HW1, test_sort_01) {
  std::vector<int> mas1 = {1,0,0,0,1,1,1,0,0,0,0, 0,0,1,0};
  sort_01(mas1);
  printMas(mas1);
  EXPECT_EQ(mas1, std::vector<int>({0,0,0,0,0,0,0,0,0,0,1,1,1,1,1}));
}

TEST(HW1, test_sort_012) {
  std::vector<int> mas = {1,0,0,2,1,1,1,0,2,0,0,2,0,1,0};
  sort_012(mas);
  printMas(mas);
  EXPECT_EQ(mas, std::vector<int>({0,0,0,0,0,0,0,1,1,1,1,1,2,2,2}));
}

TEST(HW1, test_sort_even) {
  std::vector<int> mas = {3,2,4,1,11,8,9,6,6,6,1,1,1,1,1,6,6,1,2,3,2,3,2,3,3,3,1,1,2};
  sort_even(mas);
  printMas(mas);
  EXPECT_EQ(mas, std::vector<int>({2,4,8,6,6,6,6,6,2,2,2,2,1,1,1,9,1,1,11,3,3,3,1,3,3,3,1,1,1}));
}

TEST(HW1, test_zero) {
  std::vector<int> mas = {0,0,0,0,1,2,3,0,4,5,6,7,0,8,9,0,0,0,0,10,11,12,0,0,0,0};
  sort_zero(mas);
  printMas(mas);
  EXPECT_EQ(mas, std::vector<int>({1,2,3,4,5,6,7,8,9,10,11,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0}));
}
