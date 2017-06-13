// Author: Naresh Kumar (nareshkumargangwar@gmail.com)

#include <vector>

template <typename T>
void Merge(std::vector<T>& data, int start, int mid, int end) {
  int i = start;
  int j = mid;
  std::vector<T> temp(end - start);
  int index = 0;
  while (i < mid && j < end && index < temp.size()) {
    if (data[i] < data[j]) {
      temp[index++] = data[i++];
    } else {
      temp[index++] = data[j++];
    }
  }
  while (i < mid && index < temp.size()) {
    temp[index++] = data[i++];
  }
  while (j < end && index < temp.size()) {
    temp[index++] = data[j++];
  }
  for (int i = 0; i < temp.size(); ++i) {
    data[start + i] = temp[i];
  }
}

template <typename T>
void MergeSortInernal(std::vector<T>& data, int start, int end) {
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
  int mid = (start + end) / 2;
  MergeSortInernal(data, start, mid);
  MergeSortInernal(data, mid, end);
  Merge(data, start, mid, end);
}

template <typename T>
void MergeSort(std::vector<T>& data) {
  MergeSortInernal(data, 0, data.size());
}
