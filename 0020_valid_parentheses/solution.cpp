#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

// ---------- SOLUTION ----------

class Solution {
 public:
  bool isValid(const std::string &s) {
    static const std::unordered_map<char, char> kOpeningCharToClosingChar{
        {'(', ')'}, {'{', '}'}, {'[', ']'}};
    std::stack<char> s_stack{};

    for (const auto c : s) {
      switch (c) {
        case '(':
        case '{':
        case '[':
          s_stack.push(c);
          break;

        case ')':
        case '}':
        case ']':
          if (s_stack.empty() ||
              kOpeningCharToClosingChar.at(s_stack.top()) != c) {
            return false;
          }

          s_stack.pop();
          break;
        default:
          break;
      }
    }

    return s_stack.empty();
  }
};

// ---------- TESTING ----------

int main() {
  Solution s{};

  std::cout << s.isValid("([{]})") << '\n';
  std::cout << s.isValid("()[]{}") << '\n';
  std::cout << s.isValid("(]") << '\n';
  std::cout << s.isValid("([])") << '\n';
  std::cout << s.isValid("([)]") << '\n';
}