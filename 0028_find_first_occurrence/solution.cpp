#include <iostream>
#include <string>

// ---------- SOLUTION ----------

class Solution {
public:
  int strStr(const std::string &haystack, const std::string &needle) {
    if (needle.size() > haystack.size()) {
      return -1;
    }

    for (size_t i = 0; i < haystack.size() - needle.size() + 1; ++i) {
      if (haystack[i] == needle[0] &&
          haystack.substr(i, needle.size()) == needle) {
        return i;
      }
    }
    return -1;
  }
};

// ---------- TESTING ----------

int main() {
  Solution s{};

  std::cout << s.strStr("sadbutsad", "tsad") << '\n';

  return 0;
}
