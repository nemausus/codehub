// Author: Naresh Kumar (nareshkumargangwar@gmail.com)

#include <vector>

template <typename T>
void ShiftDown(std::vector<T>& data, int i, int end) {
  int largest = i;
  int left = i * 2 + 1;
  if (left < end && data[left] > data[largest]) {
    largest = left;
  }
  int right = i * 2 + 2;
  if (right < end && data[right] > data[largest]) {
    largest = right;
  }
  if (largest != i) {
    std::swap(data[i], data[largest]);
    ShiftDown(data, largest, end);
  }
}

template <typename T>
void HeapSort(std::vector<T>& data) {
  // heapify
  for (int i = data.size() / 2 - 1; i >= 0; --i) {
    ShiftDown(data, i, data.size());
  }
  // sort
  for (int i = data.size() - 1; i >= 0; --i) {
    std::swap(data[0], data[i]);
    ShiftDown(data, 0, i);
  }
}
