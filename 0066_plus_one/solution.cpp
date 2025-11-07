#include <iostream>
#include <vector>

// ---------- SOLUTION ----------

class Solution {
public:
  std::vector<int> plusOne(std::vector<int> &digits) {
    for (int i = digits.size() - 1; i >= 0; --i) {
      if (digits[i] != 9) {
        ++digits[i];
        return digits;
      } else if (i == 0) {
        digits = std::vector(digits.size() + 1, 0);
        digits[0] = 1;
        return digits;
      } else {
        digits[i] = 0;
      }
    }

    return digits; // Should be unreachable
  }
};

// ---------- TESTING ----------

int main() {
  Solution s{};

  std::vector<int> vec{9, 1, 9};
  for (const auto &v : s.plusOne(vec)) {
    std::cout << v << '\n';
  }

  std::cout << '\n';

  std::vector<int> vec2{9, 9, 9};
  for (const auto &v : s.plusOne(vec2)) {
    std::cout << v << '\n';
  }

  return 0;
}