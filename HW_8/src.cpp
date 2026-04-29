#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

/* Префиксные суммы позволяют считать сумму любого окна длины k
 * за O(1), поэтому все окна проверяем за общий O(n). */
int maxSubarraySum(const std::vector<int> &arr, int k) {
  assert(k > 0 && k <= static_cast<int>(arr.size()));

  std::vector<int> prefix(arr.size() + 1, 0);
  for (int i = 0; i < static_cast<int>(arr.size()); ++i) {
    prefix[i + 1] = prefix[i] + arr[i];
  }

  int maxSum = prefix[k] - prefix[0];
  for (int left = 1; left + k <= static_cast<int>(arr.size()); ++left) {
    int currentSum = prefix[left + k] - prefix[left];
    maxSum = std::max(maxSum, currentSum);
  }
  return maxSum;
}

/* Если текущая префиксная сумма равна prefixSum, то каждая ранее
 * встреченная сумма prefixSum - k образует подмассив суммы k. */
int subarraySumEqualsK(const std::vector<int> &nums, int k) {
  std::unordered_map<int, int> prefixCount;
  prefixCount[0] = 1;

  int prefixSum = 0;
  int count = 0;
  for (int num : nums) {
    prefixSum += num;
    auto it = prefixCount.find(prefixSum - k);
    if (it != prefixCount.end()) {
      count += it->second;
    }
    prefixCount[prefixSum]++;
  }
  return count;
}

/* После замены 0 на -1 подмассив с равным числом нулей и единиц
 * превращается в подмассив с суммой 0. */
int findMaxLengthEqualZeroOne(const std::vector<int> &nums) {
  std::unordered_map<int, int> firstIndex;
  firstIndex[0] = -1;

  int prefixSum = 0;
  int maxLen = 0;
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    prefixSum += (nums[i] == 0 ? -1 : 1);
    auto it = firstIndex.find(prefixSum);
    if (it != firstIndex.end()) {
      maxLen = std::max(maxLen, i - it->second);
    } else {
      firstIndex[prefixSum] = i;
    }
  }
  return maxLen;
}

/* Индекс является pivot, если сумма слева равна
 * totalSum - leftSum - nums[i], то есть сумме справа. */
int pivotIndex(const std::vector<int> &nums) {
  int totalSum = 0;
  for (int num : nums) {
    totalSum += num;
  }

  int leftSum = 0;
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    if (leftSum == totalSum - leftSum - nums[i]) {
      return i;
    }
    leftSum += nums[i];
  }
  return -1;
}

/* Баланс скобок можно хранить как префиксную сумму:
 * '(' дает +1, ')' дает -1, и баланс не должен уходить в минус. */
bool isBalancedBrackets(const std::string &s) {
  int balance = 0;
  for (char ch : s) {
    if (ch == '(') {
      ++balance;
    } else {
      --balance;
    }
    if (balance < 0) {
      return false;
    }
  }
  return balance == 0;
}
