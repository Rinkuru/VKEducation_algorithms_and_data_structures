#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

struct TreeNode {
  TreeNode(int elem): val(elem) {}
  TreeNode() {}
  TreeNode *left = nullptr;
  TreeNode *right = nullptr;
  int val = 0;
  int balance_factor = 0;
};

/* Восстанавливаем дерево из массива level-order:
 * у узла с индексом i левый потомок находится в 2 * i + 1,
 * а правый - в 2 * i + 2.*/
TreeNode *buildTree(const std::vector<int> &arr, int i = 0) {
  if (i >= static_cast<int>(arr.size())) {
    return nullptr;
  }
  TreeNode *root = new TreeNode(arr[i]);
  root->left = buildTree(arr, 2 * i + 1);
  root->right = buildTree(arr, 2 * i + 2);
  return root;
}

void deleteTree(TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}


/* Сравниваем зеркальные пары узлов:
 * левый узел первого поддерева с правым узлом второго и наоборот.*/
bool isMirror(TreeNode *left, TreeNode *right) {
  if (left == nullptr && right == nullptr) {
    return true;
  }
  if (left == nullptr || right == nullptr) {
    return false;
  }
  if (left->val != right->val) {
    return false;
  }
  return isMirror(left->left, right->right) &&
         isMirror(left->right, right->left);
}


bool isSymmetric(TreeNode *root) {
  if (root == nullptr) {
    return true;
  }
  return isMirror(root->left, root->right);
}

/* BFS идет по уровням сверху вниз, поэтому первый найденный лист
 * лежит на минимальной глубине.*/
int minDepth(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }

  std::queue<std::pair<TreeNode *, int>> nodes;
  nodes.push({root, 1});

  while (!nodes.empty()) {
    TreeNode *node = nodes.front().first;
    int depth = nodes.front().second;
    nodes.pop();

    if (node->left == nullptr && node->right == nullptr) {
      return depth;
    }
    if (node->left != nullptr) {
      nodes.push({node->left, depth + 1});
    }
    if (node->right != nullptr) {
      nodes.push({node->right, depth + 1});
    }
  }
  return 0;
}


/* В BST минимум находится в самой левой вершине, максимум - в самой правой.
 * После восстановления дерева поиск крайних элементов занимает O(h).*/
long long maxMinMultiplication(const std::vector<int> &arr) {
  if (arr.empty()) {
    return 0;
  }

  TreeNode *root = buildTree(arr);
  TreeNode *minNode = root;
  TreeNode *maxNode = root;

  while (minNode->left != nullptr) {
    minNode = minNode->left;
  }
  while (maxNode->right != nullptr) {
    maxNode = maxNode->right;
  }

  long long result = 1LL * minNode->val * maxNode->val;
  deleteTree(root);
  return result;
}


/* Два дерева одинаковы, если совпадают текущие узлы
 * и рекурсивно совпадают их левые и правые поддеревья.*/
bool isSameTree(TreeNode *a, TreeNode *b) {
  if (a == nullptr && b == nullptr) {
    return true;
  }
  if (a == nullptr || b == nullptr) {
    return false;
  }
  if (a->val != b->val) {
    return false;
  }
  return isSameTree(a->left, b->left) &&
         isSameTree(a->right, b->right);
}
