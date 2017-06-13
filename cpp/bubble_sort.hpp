// Author: Naresh Kumar (nareshkumargangwar@gmail.com)

#include <vector>

template <typename T>
void BubbleSort(std::vector<T>& data) {
  for (int end = data.size() - 1; end > 0; --end) {
    bool is_sorted = true;
    for (int i = 0; i < end; ++i) {
      if (data[i] > data[i + 1]) {
        std::swap(data[i], data[i + 1]);
        is_sorted = false;
      }
    }
    if (is_sorted) {
      return;
    }
  }
}
