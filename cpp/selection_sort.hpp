// Author: Naresh Kumar (nareshkumargangwar@gmail.com)

#include <vector>

template <typename T>
void SelectionSort(std::vector<T>& data) {
  for (int i = 0; i < data.size(); ++i) {
    int min_index = i;
    for (int j = i; j < data.size(); ++j) {
      if (data[min_index] > data[j]) {
        min_index = j;
      }
    }
    std::swap(data[i], data[min_index]);
  }
}
