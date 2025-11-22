#include <iostream>
#include <vector>

// ---------- SOLUTION ----------

class Solution {
public:
  int searchInsert(const std::vector<int> &nums, const int target) {
    int low{};
    int high{static_cast<int>(nums.size()) - 1};

    while (low <= high) {
      const auto mid = low + (high - low) / 2;

      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    return low;
  }
};

// ---------- TESTING ----------

int main() {
  Solution s{};

  std::vector<int> nums1{1, 3, 5, 6};
  std::cout << s.searchInsert(nums1, 5) << '\n';

  std::vector<int> nums2{1, 3, 5, 6};
  std::cout << s.searchInsert(nums2, 0) << '\n'; // Expected: 0

  return 0;
}
