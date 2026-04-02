#include <gtest/gtest.h>
#include "src.cpp"

bool checkEQ(oneNode *n, std::vector<int> mas) {
  int i = 0;
  while (n != nullptr and i < mas.size()) {
    if (n->val == mas[i]) {
      n = n->next;
      ++i;
    } else {
      return false;
    }
  }
  return true;
}

TEST(HW2, test_reverseList) {
  oneNode *n = createList(std::vector<int>({0,1,2,3,4,5,6}));
  printList(n);
  reverseList(n);
  printList(n);
  EXPECT_TRUE(checkEQ(n, std::vector<int>({6,5,4,3,2,1,0})));
  deleteList(n);
}

TEST(HW2, test_findMidleList) {
  oneNode *n = createList(std::vector<int>({0,1,2,3,4,5,6}));
  printList(n);
  oneNode *ne = findMidleList(n);
  print(ne);
  printList(n);
  EXPECT_EQ(ne->val, 3);
  deleteList(n);
}

TEST(HW2, test_removeElem) {
  oneNode *n = createList(std::vector<int>({0,1,2,3,4,3,3,3,3,5,6}));
  printList(n);
  removeElem(n, 3);
  printList(n);
  EXPECT_TRUE(checkEQ(n, std::vector<int>({0,1,2,4,5,6})));
  deleteList(n);
}

TEST(HW2, test_lineSourceOther) {
  std::string a = "qwer";
  std::string b = "aqswdefr";
  EXPECT_TRUE(lineSourceOther(a,b));
  std::string c = "aqswdefq";
  EXPECT_FALSE(lineSourceOther(a,c));
}

TEST(HW2, test_pairSearch) {
  EXPECT_FALSE(pairSearch(std::vector<int>({}), 10));
  EXPECT_FALSE(pairSearch(std::vector<int>({7}), 14));
  EXPECT_FALSE(pairSearch(std::vector<int>({1,2,3,4,5,6,7,8,9,10,11,12,13,14}), 2));
  EXPECT_TRUE(pairSearch(std::vector<int>({1,2,3,4,5,6,7,8,9,10,11,12,13,14}), 3));
  EXPECT_TRUE(pairSearch(std::vector<int>({1,2,3,4,5,6,7,8,9,10,11,12,13,14}), 27));
  EXPECT_FALSE(pairSearch(std::vector<int>({1,2,3,4,5,6,7,8,9,10,11,12,13,14}), 28));
}

TEST(HW2, test_isPalindrom) {
  EXPECT_TRUE(isPalindrom("paap"));
  EXPECT_FALSE(isPalindrom("paapa"));
  EXPECT_TRUE(isPalindrom("paapaap"));
  EXPECT_FALSE(isPalindrom("qpaap"));
}

TEST(HW2, test_removeDuplicates) {
  std::vector<int> empty = {};
  removeDuplicates(empty);
  EXPECT_EQ(empty, std::vector<int>({}));

  std::vector<int> mas = {1, 1, 2, 3, 3, 3, 4, 5, 5};
  removeDuplicates(mas);
  EXPECT_EQ(mas, std::vector<int>({1,2,3,4,5}));
}

TEST(HW2, test_mergeSortedLists) {
  oneNode *list1 = createList(std::vector({3,6,8}));
  oneNode *list2 = createList(std::vector({4,7,9,11}));
  oneNode *merged = mergeSortedLists(list1, list2);
  printList(merged);
  EXPECT_TRUE(checkEQ(merged, std::vector<int>({3,4,6,7,8,9,11})));
  deleteList(merged);
}
