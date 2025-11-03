#include <iostream>
#include <vector>

// ---------- SOLUTION ----------

class Solution {
public:
  int removeElement(std::vector<int> &nums, const int val) {
    int counter{};
    for (size_t i = 0; i < nums.size(); ++i) {
      if (nums[i] != val) {
        if (counter != i) {
          nums[counter] = nums[i];
        }
        ++counter;
      }
    }

    return counter;
  }
};

// ---------- TESTING ----------

int main() {
  Solution s{};
  std::vector<int> nums{0, 1, 2, 2, 3, 0, 4, 2};
  auto v = s.removeElement(nums, 2);

  std::cout << v << '\n';

  for (auto num : nums) {
    std::cout << num << 'n';
  }

  return 0;
}