#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_map>

// ---------- SOLUTION ----------

class Solution {
 public:
  int romanToInt(const std::string& s) {
    static const std::unordered_map<char, int> kRomanCharToInt{
        {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50},
        {'X', 10},   {'V', 5},   {'I', 1}};

    int total{};

    for (size_t i = 0; i < s.size(); ++i) {
      const auto roman = s[i];
      const auto roman_int = kRomanCharToInt.at(roman);

      if (i != s.size() - 1) {
        const auto roman_2 = s[i + 1];
        const auto roman_2_int = kRomanCharToInt.at(roman_2);

        if (roman_int < roman_2_int) {
          total += roman_2_int - roman_int;
          ++i;
          continue;
        }
      }

      total += roman_int;
    }

    return total;
  }
};

// ---------- TESTING ----------

int main() {
  Solution s{};

  std::cout << s.romanToInt("III") << "\n";
  std::cout << s.romanToInt("LVIII") << "\n";
  std::cout << s.romanToInt("MCMXCIV") << "\n";
}