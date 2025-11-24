#include <iostream>
#include <vector>

// ---------- SOLUTION ----------

class Solution {
public:
  void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    auto it1 = nums1.rbegin() + n;
    auto it2 = nums2.rbegin();
    for (auto it3 = nums1.rbegin(); it3 != nums1.rbegin() + (m + n); ++it3) {
      if (it1 == nums1.rbegin() + (m + n) ||
          (it2 != nums2.rend() && *it2 > *it1)) {
        *it3 = *it2;
        ++it2;
      } else {
        *it3 = *it1;
        ++it1;
      }
    }
  }
};

// ---------- TESTING ----------

void printVector(const std::vector<int> &vec, int validSize = -1) {
  std::cout << '[';
  int size = (validSize == -1) ? vec.size() : validSize;
  for (int i = 0; i < size; ++i) {
    std::cout << vec[i];
    if (i < size - 1)
      std::cout << ", ";
  }
  std::cout << ']';
}

int main() {
  Solution s{};



  return 0;
}
