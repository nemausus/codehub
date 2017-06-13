// Author: Naresh Kumar (nareshkumargangwar@gmail.com)

#include <functional>
#include <iostream>
#include <vector>

#include "bubble_sort.hpp"
#include "heap_sort.hpp"
#include "insertion_sort.hpp"
#include "merge_sort.hpp"
#include "quick_sort.hpp"
#include "selection_sort.hpp"
#include "utils.hpp"

int main() {
  auto test = [](const std::string& name,
                 const std::vector<std::vector<int>>& tests,
                 std::function<void(std::vector<int>&)> f) {
    std::cout << "Running " << name << std::endl;
    std::string status = "OK";
    for (int t = 0; t < tests.size(); ++t) {
      auto actual = tests[t];
      f(actual);
      auto exptected = tests[t];
      std::sort(exptected.begin(), exptected.end());
      if (actual != exptected) {
        std::cout << " Failure " << utils::ToString(tests[t]) << std::endl;
        status = "FAILED";
      }
    }
    std::cout << "Status=" << status << std::endl << std::endl;
  };

  std::vector<std::vector<int>> tests = {
      {},
      {0},
      {0, 0},
      {0, 0, 0},
      {0, 1},
      {1, 0},
      {0, 1, 2},
      {0, 2, 1},
      {1, 0, 2},
      {1, 2, 0},
      {2, 0, 1},
      {2, 1, 0},
      {0, 1, 1},
      {1, 0, 1},
      {1, 1, 0},
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
      {10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
      {42, 9, 17, 54, 602, -3, 54, 999, -11},
      {-11, -3, 9, 17, 42, 54, 54, 602, 999},
      {-13, -53, 23, -47, -74, -38, 97, -19, 80, 81},
      {23, -82, -96, 52, 91, 45, -77, 80, 21, 92},
      {-70, 33, 42, 59, 58, -22, 18, -27, -24, -71},
      {-35, 52, 50, 24, 67, -26, -8, 78, -2, -88},
      {-73, -13, -47, -98, -67, -24, -83, 98, 39, 49},
      {-29, -88, 34, 88, 30, 70, -13, 69, 7, 46},
      {29, 3, -16, -8, -22, -57, 3, 70, 86, 64},
      {-93, 76, 93, 62, -6, -43, 59, -84, -71, -49},
      {45, 9, -49, 54, -15, 71, 33, 66, 1, 74},
      {79, 1, 28, -1, 51, 32, 41, 43, -6, -30},
  };
  test("BubbleSort", tests, BubbleSort<int>);
  test("HeapSort", tests, HeapSort<int>);
  test("InsertionSort", tests, InsertionSort<int>);
  test("MergetSort", tests, MergeSort<int>);
  test("QuickSort", tests, QuickSort<int>);
  test("SelectionSort", tests, SelectionSort<int>);
}
