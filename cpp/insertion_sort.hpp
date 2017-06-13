// Author: Naresh Kumar (nareshkumargangwar@gmail.com)

#include <vector>

template <typename T>
void InsertionSort(std::vector<T>& data) {
  for (int i = 0; i < data.size(); ++i) {
    for (int j = i; j > 0; --j) {
      if (data[j] < data[j - 1]) {
        std::swap(data[j], data[j - 1]);
      }
    }
  }
}
