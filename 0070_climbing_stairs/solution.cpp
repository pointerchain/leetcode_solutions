#include <iostream>
#include <unordered_map>

// ---------- SOLUTION ----------

class Solution {
public:
  int climbStairs(const int n) {
    static std::unordered_map<int, int> results{};

    if (n == 1 || n == 2) {
      return n;
    }

    auto it = results.find(n);
    if (it != results.end()) {
      return it->second;
    }

    results[n] = climbStairs(n - 2) + climbStairs(n - 1);

    return results[n];
  }
};

// ---------- TESTING ----------

int main() {
  Solution s{};

  std::cout << s.climbStairs(3) << ' ' << s.climbStairs(4) << '\n';

  return 0;
}

// 1 = 1
// 2 = 1 + 1, 2
// 3 = 1 + 1 + 1, 1 + 2, 2 + 1
// 4 = 1 + 1 + 1 + 1, 2 + 2, 2 + 1 + 1, 1 + 2, + 1, 1 + 1 + 2