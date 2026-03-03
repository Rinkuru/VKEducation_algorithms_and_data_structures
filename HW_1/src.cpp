#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cassert>

// функция для отладки
void printMas(const std::vector<int> &mas) {
  for(size_t i = 0; i < mas.size(); ++i) {
    std::cout << mas[i] << " ";
  }
  std::cout << std::endl;
}

void swap(int &a, int &b) {
  int c = a;
  a = b;
  b = c;
}
/* Вспомогательная функция для переворота массива*/
void reverseMas(std::vector<int> &mas, int left, int right) {
  assert(0 <= left && left < right && right < mas.size());
  while(left < right) {
    swap(mas[left], mas[right]);
    ++left;
    --right;
  }
}
/* сдвинуть справа налево часть массива, которая указана параметром k.*/
void reverseMas(std::vector<int> &mas, int k) {
  int n = mas.size()-1;
  reverseMas(mas, 0, n);
  reverseMas(mas, 0, k-1);
  reverseMas(mas, k, n);
}
/* Слияние двух отсортированных массивов*/
std::vector<int> mergeMas(std::vector<int> &a, std::vector<int> &b) {
  std::vector<int> res;
  int i = 0, j = 0;
  while(i < a.size() and j < b.size()) {
    if(a[i] < b[j]) {
      res.push_back(a[i]);
      ++i;
    } else {
      res.push_back(b[j]);
      ++j;
    }
  }
  while (i < a.size()) {
    res.push_back(a[i]);
    ++i;
  }
  while (j < b.size()) {
    res.push_back(b[j]);
    ++j;
  }
  return res; 
}
/* Слияние двух отсортированных массивов (без дополнительных аллокаций)*/
std::vector<int> &mergeMas2(std::vector<int> &a, std::vector<int> &b) {
  assert(a.size() > b.size());
  int zero = a.size() -1, j = b.size() -1;
  int i = zero - j - 1;
  while (j >= 0) {
    if (a[i] > b[j]) {
      a[zero] = a[i];
      zero--;
      i--;
    } else {
      a[zero] = b[j];
      zero--;
      j--;
    }
  }
  return a;
}
/* Сортировка массива из 0 и 1*/
void sort_01(std::vector<int> &a) {
  int i = 0, j = a.size() - 1;
  while (i < j) {
    if (a[i] == 1) {
      swap(a[i], a[j]);
      --j;
    } else {
      ++i;
    }
  }
  return;
}
/* Задача флага Нидерландов
 * Дан массив, состоящий из 0, 1 и 2.*/
void sort_012(std::vector<int> &a) {
  int i = 0, m = 0, j = a.size() - 1;
  while (m <= j) {
    if (a[m] == 2) {
      swap(a[m], a[j]);
      --j;
    } else if (a[m] == 0) {
      swap(a[m], a[i]);
      m++;
      i++;
    } else if (a[m] == 1) {
      m++;
    } else {
      assert(false);
    }
  }
  return;
}
/*Передвинуть чётные числа вперёд*/
void sort_even(std::vector<int> &a) {
  int i = 0, j = 0;
  while (j < a.size()) {
    if (a[j] % 2 == 0) {
      swap(a[i], a[j]);
      i++;
      j++;
    } else {
      j++;
    }
  }
}
/*Нули в конец*/
void sort_zero(std::vector<int> &a) {
  int zero = 0, i = 0;
  while (i + zero < a.size()) {
    while (a[i+zero] == 0) {
      zero++;
    }
    a[i] = a[i+zero];
    i++;
  }
  while(zero > 0) {
    a[a.size() - zero] = 0;
    zero--;
  }
}