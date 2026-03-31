#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// функция для отладки
void printMas(const std::vector<int> &mas) {
  for (size_t i = 0; i < mas.size(); ++i) {
    std::cout << mas[i] << " ";
  }
  std::cout << std::endl;
}

/* найти целую часть квадратного корня
 * бинарный поиск работает за O(log n), потому что на каждом шаге
 * мы отбрасываем половину диапазона [l, r] */
int binarySearchSqrt(int target) {
  if (target < 0) {
    return -1;
  }
  if (target < 2) {
    return target;
  }

  int l = 0;
  int r = target;
  int res = 0;
  while (l <= r) {
    int middle = l + (r - l) / 2;
    long long square = 1LL * middle * middle;
    if (square == target) {
      return middle;
    }
    if (square < target) {
      res = middle;
      l = middle + 1;
    } else {
      r = middle - 1;
    }
  }
  return res;
}

/* минимальное время для N копий на двух ксероксах
 * первую копию делаем на более быстром ксероксе,
 * после этого бинарным поиском ищем время для оставшихся N - 1 копий */
long long copyTime(int n, int x, int y) {
  if (n <= 0) {
    return 0;
  }
  if (n == 1) {
    return std::min(x, y);
  }

  long long firstCopy = std::min(x, y);
  long long l = 0;
  long long r = 1LL * (n - 1) * std::max(x, y);
  while (l + 1 < r) {
    long long middle = (l + r) / 2;
    long long copies = middle / x + middle / y;
    if (copies < n - 1) {
      l = middle;
    } else {
      r = middle;
    }
  }
  return r + firstCopy;
}

/* накормить максимум животных
 * сортируем животных и еду, после чего каждой порцией
 * пытаемся накормить самое "дешевое" ещё не накормленное животное */
int feedAnimals(std::vector<int> animals, std::vector<int> food) {
  if (animals.empty() || food.empty()) {
    return 0;
  }

  std::sort(animals.begin(), animals.end());
  std::sort(food.begin(), food.end());

  int count = 0;
  for (int portion : food) {
    if (count == static_cast<int>(animals.size())) {
      break;
    }
    if (portion >= animals[count]) {
      ++count;
    }
  }
  return count;
}

/* найти лишнюю букву между двумя строками
 * считаем буквы во второй строке, потом вычитаем буквы первой строки,
 * в таблице останется только добавленный символ */
std::string extraLetter(const std::string &a, const std::string &b) {
  std::unordered_map<char, int> hashMapB;
  for (char letter : b) {
    hashMapB[letter]++;
  }

  for (char letter : a) {
    auto it = hashMapB.find(letter);
    if (it != hashMapB.end()) {
      it->second--;
      if (it->second == 0) {
        hashMapB.erase(it);
      }
    }
  }

  for (const auto &[letter, count] : hashMapB) {
    if (count > 0) {
      return std::string(1, letter);
    }
  }
  return "";
}

/* сумма двух элементов массива за O(n)
 * в хеш-таблице храним уже просмотренные числа и их индексы,
 * поэтому на каждом шаге можем за O(1) проверить нужную пару */
std::vector<int> twoSum(const std::vector<int> &data, int target) {
  std::unordered_map<int, int> cache;
  for (int i = 0; i < static_cast<int>(data.size()); ++i) {
    int diff = target - data[i];
    auto it = cache.find(diff);
    if (it != cache.end()) {
      return {it->second, i};
    }
    cache[data[i]] = i;
  }
  return {};
}
