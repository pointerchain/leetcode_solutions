#include <iostream>
#include <unordered_map>
#include <vector>

// ---------- SOLUTION ----------

class Solution {
 public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> num_to_index{};

    for (size_t i = 0; i < nums.size(); ++i) {
      const int v{nums[i]};
      const int complement{target - v};
      const auto it = num_to_index.find(complement);

      if (it != num_to_index.end()) {
        return {it->second, static_cast<int>(i)};
      }

      num_to_index[v] = i;
    }

    return {};
  }
};

// ---------- TESTING ----------

int main() {
  auto x = Solution{};

  std::vector<int> nums{2, 4, 10, 5, 8};
  auto y = x.twoSum(nums, 18);

  std::cout << y[0] << " | " << y[1] << '\n';

  return 0;
}