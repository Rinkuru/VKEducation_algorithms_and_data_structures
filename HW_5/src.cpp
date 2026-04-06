#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <cassert>
#include <functional>
#include <queue>
#include <stack>
#include <tuple>
#include <vector>

#include "../HW_4/src.cpp"

/* Полное дерево при обходе в ширину после первого nullptr
 * больше не должно содержать непустых узлов.*/
bool isCompleteTree(TreeNode *root) {
  if (root == nullptr) {
    return true;
  }

  std::queue<TreeNode *> nodes;
  nodes.push(root);
  bool seenNull = false;

  while (!nodes.empty()) {
    TreeNode *node = nodes.front();
    nodes.pop();

    if (node == nullptr) {
      seenNull = true;
    } else {
      if (seenNull) {
        return false;
      }
      nodes.push(node->left);
      nodes.push(node->right);
    }
  }
  return true;
}

/* В мин-куче храним текущий минимум каждого массива:
 * (значение, индекс массива, индекс элемента).*/
std::vector<int> mergeKSortedArrays(const std::vector<std::vector<int>> &sortedArrays) {
  using HeapNode = std::tuple<int, int, int>;
  std::priority_queue<HeapNode, std::vector<HeapNode>, std::greater<HeapNode>> minHeap;
  std::vector<int> mergedArray;

  for (int i = 0; i < static_cast<int>(sortedArrays.size()); ++i) {
    if (!sortedArrays[i].empty()) {
      minHeap.push({sortedArrays[i][0], i, 0});
    }
  }

  while (!minHeap.empty()) {
    int value = std::get<0>(minHeap.top());
    int arrayIdx = std::get<1>(minHeap.top());
    int elementIdx = std::get<2>(minHeap.top());
    minHeap.pop();

    mergedArray.push_back(value);
    if (elementIdx + 1 < static_cast<int>(sortedArrays[arrayIdx].size())) {
      minHeap.push({sortedArrays[arrayIdx][elementIdx + 1], arrayIdx, elementIdx + 1});
    }
  }
  return mergedArray;
}

/* Для k-го наименьшего держим в куче k наименьших элементов,
 * а на вершине остается худший из них, то есть ответ.*/
int kthSmallest(const std::vector<int> &data, int k) {
  assert(k > 0 && k <= static_cast<int>(data.size()));

  std::priority_queue<int> maxHeap;
  for (int value : data) {
    maxHeap.push(value);
    if (static_cast<int>(maxHeap.size()) > k) {
      maxHeap.pop();
    }
  }
  return maxHeap.top();
}

/* Для k-го наибольшего симметрично держим min-heap размера k.*/
int kthLargest(const std::vector<int> &data, int k) {
  assert(k > 0 && k <= static_cast<int>(data.size()));

  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
  for (int value : data) {
    minHeap.push(value);
    if (static_cast<int>(minHeap.size()) > k) {
      minHeap.pop();
    }
  }
  return minHeap.top();
}

/* Inorder BST идет по элементам в возрастающем порядке.*/
int kthSmallestInBST(TreeNode *root, int k) {
  assert(root != nullptr);
  assert(k > 0);

  std::stack<TreeNode *> nodes;
  TreeNode *current = root;
  int counter = 0;

  while (!nodes.empty() || current != nullptr) {
    while (current != nullptr) {
      nodes.push(current);
      current = current->left;
    }

    current = nodes.top();
    nodes.pop();
    ++counter;
    if (counter == k) {
      return current->val;
    }
    current = current->right;
  }

  assert(false);
  return 0;
}

/* Reverse inorder BST идет по элементам в убывающем порядке.*/
int kthLargestInBST(TreeNode *root, int k) {
  assert(root != nullptr);
  assert(k > 0);

  std::stack<TreeNode *> nodes;
  TreeNode *current = root;
  int counter = 0;

  while (!nodes.empty() || current != nullptr) {
    while (current != nullptr) {
      nodes.push(current);
      current = current->right;
    }

    current = nodes.top();
    nodes.pop();
    ++counter;
    if (counter == k) {
      return current->val;
    }
    current = current->left;
  }

  assert(false);
  return 0;
}

/* Высоты детей вычисляем раньше корня, поэтому баланс-фактор
 * удобно заполнять постфиксным обходом.*/
int calculateHeightsAndBalance(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }

  int leftHeight = calculateHeightsAndBalance(root->left);
  int rightHeight = calculateHeightsAndBalance(root->right);
  root->balance_factor = leftHeight - rightHeight;
  return 1 + std::max(leftHeight, rightHeight);
}

/* Зеркальное дерево получаем, если у каждого узла
 * поменять детей местами и повторить это для поддеревьев.*/
TreeNode *mirrorTree(TreeNode *root) {
  if (root == nullptr) {
    return nullptr;
  }

  TreeNode *tmp = root->left;
  root->left = root->right;
  root->right = tmp;

  mirrorTree(root->left);
  mirrorTree(root->right);
  return root;
}
