#include <gtest/gtest.h>
#include "src.cpp"

TEST(HW5, test_isCompleteTree_empty) {
  EXPECT_TRUE(isCompleteTree(nullptr));
}

TEST(HW5, test_isCompleteTree_single) {
  TreeNode *root = new TreeNode(1);
  EXPECT_TRUE(isCompleteTree(root));
  deleteTree(root);
}

TEST(HW5, test_isCompleteTree_true) {
  TreeNode *root = buildTree(std::vector<int>({1,2,3,4,5,6}));
  EXPECT_TRUE(isCompleteTree(root));
  deleteTree(root);
}

TEST(HW5, test_isCompleteTree_false) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->right->right = new TreeNode(7);

  EXPECT_FALSE(isCompleteTree(root));
  deleteTree(root);
}

TEST(HW5, test_mergeKSortedArrays_empty) {
  EXPECT_EQ(mergeKSortedArrays({}), std::vector<int>({}));
}

TEST(HW5, test_mergeKSortedArrays_with_empty_arrays) {
  EXPECT_EQ(
    mergeKSortedArrays(std::vector<std::vector<int>>({{}, {1,3,5}, {}, {2,4}})),
    std::vector<int>({1,2,3,4,5})
  );
}

TEST(HW5, test_mergeKSortedArrays_duplicates_and_negative) {
  EXPECT_EQ(
    mergeKSortedArrays(std::vector<std::vector<int>>({{-5,-1,4}, {-3,-3,2}, {0,2,2}})),
    std::vector<int>({-5,-3,-3,-1,0,2,2,2,4})
  );
}

TEST(HW5, test_kthSmallest) {
  std::vector<int> data = {7,4,6,3,9,1,4};
  EXPECT_EQ(kthSmallest(data, 1), 1);
  EXPECT_EQ(kthSmallest(data, 3), 4);
  EXPECT_EQ(kthSmallest(data, static_cast<int>(data.size())), 9);
}

TEST(HW5, test_kthLargest) {
  std::vector<int> data = {7,4,6,3,9,1,4};
  EXPECT_EQ(kthLargest(data, 1), 9);
  EXPECT_EQ(kthLargest(data, 2), 7);
  EXPECT_EQ(kthLargest(data, static_cast<int>(data.size())), 1);
}

TEST(HW5, test_kthSmallestInBST) {
  TreeNode *root = buildTree(std::vector<int>({8,4,12,2,6,10,14,1,3,5,7,9,11,13,15}));
  EXPECT_EQ(kthSmallestInBST(root, 1), 1);
  EXPECT_EQ(kthSmallestInBST(root, 5), 5);
  EXPECT_EQ(kthSmallestInBST(root, 15), 15);
  deleteTree(root);
}

TEST(HW5, test_kthLargestInBST) {
  TreeNode *root = buildTree(std::vector<int>({8,4,12,2,6,10,14,1,3,5,7,9,11,13,15}));
  EXPECT_EQ(kthLargestInBST(root, 1), 15);
  EXPECT_EQ(kthLargestInBST(root, 4), 12);
  EXPECT_EQ(kthLargestInBST(root, 15), 1);
  deleteTree(root);
}

TEST(HW5, test_calculateHeightsAndBalance_balanced_tree) {
  TreeNode *root = buildTree(std::vector<int>({4,2,6,1,3,5,7}));
  EXPECT_EQ(calculateHeightsAndBalance(root), 3);
  EXPECT_EQ(root->balance_factor, 0);
  EXPECT_EQ(root->left->balance_factor, 0);
  EXPECT_EQ(root->right->balance_factor, 0);
  deleteTree(root);
}

TEST(HW5, test_calculateHeightsAndBalance_skewed_tree) {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(1);

  EXPECT_EQ(calculateHeightsAndBalance(root), 3);
  EXPECT_EQ(root->balance_factor, 2);
  EXPECT_EQ(root->left->balance_factor, 1);
  EXPECT_EQ(root->left->left->balance_factor, 0);
  deleteTree(root);
}

TEST(HW5, test_mirrorTree_empty) {
  EXPECT_EQ(mirrorTree(nullptr), nullptr);
}

TEST(HW5, test_mirrorTree_structure) {
  TreeNode *root = buildTree(std::vector<int>({1,2,3,4,5,6,7}));
  TreeNode *mirrored = mirrorTree(root);

  ASSERT_NE(mirrored, nullptr);
  ASSERT_NE(mirrored->left, nullptr);
  ASSERT_NE(mirrored->right, nullptr);
  EXPECT_EQ(mirrored->left->val, 3);
  EXPECT_EQ(mirrored->right->val, 2);
  EXPECT_EQ(mirrored->left->left->val, 7);
  EXPECT_EQ(mirrored->left->right->val, 6);
  EXPECT_EQ(mirrored->right->left->val, 5);
  EXPECT_EQ(mirrored->right->right->val, 4);
  deleteTree(root);
}

TEST(HW5, test_mirrorTree_double_mirror) {
  TreeNode *root = buildTree(std::vector<int>({1,2,3,4,5,6,7}));
  mirrorTree(root);
  mirrorTree(root);

  ASSERT_NE(root, nullptr);
  EXPECT_EQ(root->val, 1);
  EXPECT_EQ(root->left->val, 2);
  EXPECT_EQ(root->right->val, 3);
  EXPECT_EQ(root->left->left->val, 4);
  EXPECT_EQ(root->left->right->val, 5);
  EXPECT_EQ(root->right->left->val, 6);
  EXPECT_EQ(root->right->right->val, 7);
  deleteTree(root);
}
