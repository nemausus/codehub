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
  auto test = [](const std::vector<std::vector<int>>& tests,
                 std::function<void(std::vector<int>&)> f) {
    int fail_count = 0;
    for (int t = 0; t < tests.size(); ++t) {
      auto actual = tests[t];
      f(actual);
      auto exptected = tests[t];
      std::sort(exptected.begin(), exptected.end());
      if (actual != exptected) {
        std::cout << " Test failed " << utils::ToString(tests[t]) << std::endl;
        ++fail_count;
      }
    }
    std::cout << "failed=" << fail_count << "/" << tests.size() << std::endl;
  };

  std::vector<std::vector<int>> tests = {
      {},           {1},          {1, 2},    {5, 4, 3, 2, 1},
      {1, 2, 3, 4}, {5, 1, 3, 2}, {5, 1, 3}, {1, 5, 3}};
  test(tests, BubbleSort<int>);
  test(tests, HeapSort<int>);
  test(tests, InsertionSort<int>);
  test(tests, MergeSort<int>);
  test(tests, QuickSort<int>);
  test(tests, SelectionSort<int>);
}
