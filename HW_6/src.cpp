#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/* Идем по массиву один раз:
 * currentLen хранит длину текущего возрастающего отрезка,
 * bestLen - длину лучшего из уже найденных. */
int longestIncreasingSubarray(const std::vector<int> &nums) {
  if (nums.empty()) {
    return 0;
  }

  int currentLen = 1;
  int bestLen = 1;
  for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
    if (nums[i - 1] < nums[i]) {
      ++currentLen;
    } else {
      currentLen = 1;
    }
    bestLen = std::max(bestLen, currentLen);
  }
  return bestLen;
}

/* Каждая внутренняя ячейка треугольника равна сумме двух ячеек
 * над ней, поэтому строки удобно строить итерационно сверху вниз. */
std::vector<std::vector<int>> pascalTriangle(int n) {
  if (n <= 0) {
    return {};
  }

  std::vector<std::vector<int>> triangle;
  for (int row = 0; row < n; ++row) {
    triangle.push_back(std::vector<int>(row + 1, 1));
    for (int col = 1; col < row; ++col) {
      triangle[row][col] = triangle[row - 1][col - 1] + triangle[row - 1][col];
    }
  }
  return triangle;
}

/* dp[i] - минимальное количество монет для суммы i.
 * Переход dp[i] = min(dp[i], dp[i - coin] + 1) перебирает,
 * какую монету взять последней для суммы i. */
int coinChange(const std::vector<int> &coins, int amount) {
  if (amount < 0) {
    return -1;
  }
  if (amount == 0) {
    return 0;
  }

  std::vector<int> dp(amount + 1, amount + 1);
  dp[0] = 0;

  for (int i = 1; i <= amount; ++i) {
    for (int coin : coins) {
      if (coin <= i) {
        dp[i] = std::min(dp[i], dp[i - coin] + 1);
      }
    }
  }

  if (dp[amount] == amount + 1) {
    return -1;
  }
  return dp[amount];
}

/* Расширяемся от каждого символа и между соседними символами.
 * Так покрываем палиндромы и нечетной, и четной длины за O(n^2). */
std::string longestPalindrome(const std::string &s) {
  if (s.empty()) {
    return "";
  }

  int bestLeft = 0;
  int bestRight = 0;

  auto expandAroundCenter = [&](int left, int right) {
    while (left >= 0 && right < static_cast<int>(s.length()) && s[left] == s[right]) {
      if (right - left > bestRight - bestLeft) {
        bestLeft = left;
        bestRight = right;
      }
      --left;
      ++right;
    }
  };

  for (int i = 0; i < static_cast<int>(s.length()); ++i) {
    expandAroundCenter(i, i);
    expandAroundCenter(i, i + 1);
  }

  return s.substr(bestLeft, bestRight - bestLeft + 1);
}
