#include <gtest/gtest.h>
#include "src.cpp"

TEST(HW4, test_buildTree_empty) {
  TreeNode *root = buildTree(std::vector<int>({}));
  EXPECT_EQ(root, nullptr);
}

TEST(HW4, test_buildTree_single) {
  TreeNode *root = buildTree(std::vector<int>({42}));
  ASSERT_NE(root, nullptr);
  EXPECT_EQ(root->val, 42);
  EXPECT_EQ(root->left, nullptr);
  EXPECT_EQ(root->right, nullptr);
  deleteTree(root);
}

TEST(HW4, test_buildTree_full) {
  TreeNode *root = buildTree(std::vector<int>({1,2,3,4,5,6,7}));
  ASSERT_NE(root, nullptr);
  ASSERT_NE(root->left, nullptr);
  ASSERT_NE(root->right, nullptr);
  ASSERT_NE(root->left->left, nullptr);
  ASSERT_NE(root->left->right, nullptr);
  ASSERT_NE(root->right->left, nullptr);
  ASSERT_NE(root->right->right, nullptr);

  EXPECT_EQ(root->val, 1);
  EXPECT_EQ(root->left->val, 2);
  EXPECT_EQ(root->right->val, 3);
  EXPECT_EQ(root->left->left->val, 4);
  EXPECT_EQ(root->left->right->val, 5);
  EXPECT_EQ(root->right->left->val, 6);
  EXPECT_EQ(root->right->right->val, 7);
  deleteTree(root);
}

TEST(HW4, test_isSymmetric_true) {
  TreeNode *root = buildTree(std::vector<int>({1,2,2,3,4,4,3}));
  EXPECT_TRUE(isSymmetric(root));
  deleteTree(root);
}

TEST(HW4, test_isSymmetric_false_by_value) {
  TreeNode *root = buildTree(std::vector<int>({1,2,2,3,4,3,5}));
  EXPECT_FALSE(isSymmetric(root));
  deleteTree(root);
}

TEST(HW4, test_isSymmetric_false_by_structure) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);
  root->left->right = new TreeNode(3);
  root->right->right = new TreeNode(3);

  EXPECT_FALSE(isSymmetric(root));
  deleteTree(root);
}

TEST(HW4, test_isSymmetric_empty) {
  EXPECT_TRUE(isSymmetric(nullptr));
}

TEST(HW4, test_minDepth_empty) {
  EXPECT_EQ(minDepth(nullptr), 0);
}

TEST(HW4, test_minDepth_single) {
  TreeNode *root = buildTree(std::vector<int>({10}));
  EXPECT_EQ(minDepth(root), 1);
  deleteTree(root);
}

TEST(HW4, test_minDepth_bfs_finds_nearest_leaf) {
  TreeNode *root = buildTree(std::vector<int>({1,2,3,4,5}));
  EXPECT_EQ(minDepth(root), 2);
  deleteTree(root);
}

TEST(HW4, test_minDepth_only_one_branch) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(3);

  EXPECT_EQ(minDepth(root), 3);
  deleteTree(root);
}

TEST(HW4, test_maxMinMultiplication_regular_bst) {
  EXPECT_EQ(maxMinMultiplication(std::vector<int>({8,4,12,2,6,10,14})), 28);
}

TEST(HW4, test_maxMinMultiplication_single_node) {
  EXPECT_EQ(maxMinMultiplication(std::vector<int>({5})), 25);
}

TEST(HW4, test_maxMinMultiplication_negative_values) {
  EXPECT_EQ(maxMinMultiplication(std::vector<int>({0,-10,10,-20,-5,5,20})), -400);
}

TEST(HW4, test_maxMinMultiplication_empty) {
  EXPECT_EQ(maxMinMultiplication(std::vector<int>({})), 0);
}

TEST(HW4, test_isSameTree_true) {
  TreeNode *a = buildTree(std::vector<int>({1,2,3,4,5,6,7}));
  TreeNode *b = buildTree(std::vector<int>({1,2,3,4,5,6,7}));

  EXPECT_TRUE(isSameTree(a, b));
  deleteTree(a);
  deleteTree(b);
}

TEST(HW4, test_isSameTree_false_by_value) {
  TreeNode *a = buildTree(std::vector<int>({1,2,3}));
  TreeNode *b = buildTree(std::vector<int>({1,2,4}));

  EXPECT_FALSE(isSameTree(a, b));
  deleteTree(a);
  deleteTree(b);
}

TEST(HW4, test_isSameTree_false_by_structure) {
  TreeNode *a = new TreeNode(1);
  a->left = new TreeNode(2);
  a->right = new TreeNode(3);

  TreeNode *b = new TreeNode(1);
  b->left = new TreeNode(2);
  b->left->left = new TreeNode(3);

  EXPECT_FALSE(isSameTree(a, b));
  deleteTree(a);
  deleteTree(b);
}

TEST(HW4, test_isSameTree_empty) {
  EXPECT_TRUE(isSameTree(nullptr, nullptr));
}
