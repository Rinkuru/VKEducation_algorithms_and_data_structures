#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cassert>

struct oneNode {
  oneNode(int elem): val(elem) {};
  oneNode() {};
  oneNode *next = nullptr;
  int val;
};

// функция для отладки
void print(oneNode *n) {
  std::cout << n->val << std::endl;
}

void printList(oneNode *n) {
  while (n->next != nullptr) {
    std::cout << n->val << " ";
    n = n->next;
  }
  std::cout << n->val << std::endl;
}

oneNode *createList(std::vector<int> mas) {
  if (mas.empty()) return nullptr;
  oneNode *head = nullptr;
  while (!mas.empty()) {
      oneNode *node = new oneNode;
      node->val = mas.back();
      mas.pop_back();
      node->next = head;
      head = node;
  }
  return head;
}

void deleteList(oneNode *head) {
  while (head != nullptr) {
    oneNode* tmp = head->next;
    delete head;
    head = tmp;
  }
}

/* развернуть массив
 * указатель на каждом пройденном ноде меняет свою ссылку на прошлую ноду
 * при этом мы дополнительно сохраняем ссылку на следующий ноду
 * работает за О(n) потому что проходим по каждому элементу*/
void reverseList (oneNode *&head) {
  oneNode *prev = nullptr;
  while (head != nullptr) {
    oneNode *next = head->next;
    head->next = prev;
    prev = head;
    head = next;
  }
  head = prev;
  return;
}

/* найти середину массива
 * быстрый указатель позволяет решить эту задачу за один проход,
 * так как он удаляется от медленного каждый раз всего на 1 ноду*/
oneNode *findMidleList(oneNode *n) {
  oneNode *res = n;
  oneNode *fast = n;
  while(fast != nullptr and fast->next != nullptr) {
    res = res->next;
    fast = fast->next->next;
  }
  return res;
}

/* удаление элемента из списка
 * удаляем красиво, добавляем нулевой элемент и это будет нашё новой головой
 * а значит любой элемент обрабатываем как внутренний элемент*/
void removeElem(oneNode *&n, int elem) {
  oneNode *zero = new oneNode;
  zero->next = n;
  oneNode *prev = zero;
  oneNode *cur = n;
  while (cur != nullptr) {
    if (cur->val == elem) {
      prev->next = cur->next;
      delete(cur);
      cur = prev;
    } else {
      prev = cur;
    }
    cur = cur->next;
  }
  n = zero->next;
  delete(zero);
}

/* является ли одна строка исходной для другой
 * проверяю в том же порядке ли встречаются символы из первой строки во второй строке
 * если нашли все символы из первой строки, то ок*/
bool lineSourceOther(std::string a, std::string b) {
  int i = 0, j = 0;
  while (i < a.length() and j < b.length()) {
    if (a[i] == b[j]) {
      i++;
    }
    j++;
  }
  return i == a.length();
}

/* Необходимо определить, существуют ли два элемента, сумма которых равна target.
 * этот подход работает за O(n/2), что равно  O(n)*/
bool pairSearch(std::vector<int> mas, int target) {
  int l = 0, r = mas.size();
  while (l < r) {
    if (target > mas[l] + mas[r]) {
      l++;
    } else if (target < mas[l] + mas[r]) {
      r--;
    } else if (target == mas[l] + mas[r]) {
      return true;
    }
  }
  return false;
}

/* Является ли слово палиндромом?
 * алгоритм работает за линеёное время потому что перебор по каждому символу*/
bool isPalindrom(std::string str) {
  int l = 0, r = str.length() - 1;
  while (l <= r) {
    if (str[l] != str[r])
      return false;
    l++;
    r--;
  }
  return true;
}

/* удаление дупликатов из массива*/
void removeDuplicates(std::vector<int> &arr) {
  int slow = 0, fast = 1;
  while (fast < arr.size()) {
    if (arr[fast] != arr[slow]) {
      ++slow;
      arr[slow] = arr[fast];
    }
    ++fast;
  }
  arr.resize(slow + 1);
}

/* Слияние двух отсортированных списков
 * алгоритм не требует доп памяти потому что мы меняем только ссылкы на элементы, но не удаляем и не добавляем новые элементы
 * работает за O(n+m) так как в худшем случае надо пройти по каждому массиву польностью*/
oneNode *mergeSortedLists(oneNode *a, oneNode *b) {
  oneNode zero(0);
  oneNode *tail = &zero;
  while (a != nullptr and b != nullptr) {
    if (a->val <= b->val) {
      tail->next = a;
      a = a->next;
    } else {
      tail->next = b;
      b = b->next;
    }
    tail = tail->next;
  }

  if (a != nullptr) {
    tail->next = a;
  } else if (b != nullptr) {
    tail->next = b;
  }
  return zero.next;
}
