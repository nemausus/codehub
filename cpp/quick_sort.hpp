// Author: Naresh Kumar (nareshkumargangwar@gmail.com)

#include <vector>

template <typename T>
void QuickSortInternal(std::vector<T>& data, int start, int end) {
  // Single element is always sorted.
  if (end - start < 2) {
    return;
  }
  // Array range has two elements, sort them by swapping if necessary.
  if (end - start == 2) {
    if (data[start] > data[end - 1]) {
      std::swap(data[start], data[end - 1]);
    }
    return;
  }
  T pivot = data[end - 1];
  int i = start;
  int j = end - 2;
  int loop = 10;
  while (i <= j && loop--) {
    if (data[i] < pivot) {
      ++i;
    } else {
      std::swap(data[i], data[j]);
      --j;
    }
  }
  std::swap(data[i], data[end - 1]);
  QuickSortInternal(data, start, i);
  QuickSortInternal(data, i + 1, end);
}

template <typename T>
void QuickSort(std::vector<T>& data) {
  QuickSortInternal(data, 0, data.size());
}
