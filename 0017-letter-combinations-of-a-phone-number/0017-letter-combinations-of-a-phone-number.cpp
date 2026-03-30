#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) return {};

        std::vector<std::string> mapping = {
            "",      // 0
            "",      // 1
            "abc",   // 2
            "def",   // 3
            "ghi",   // 4
            "jkl",   // 5
            "mno",   // 6
            "pqrs",  // 7
            "tuv",   // 8
            "wxyz"   // 9
        };

        std::vector<std::string> result;
        std::string current;

        backtrack(digits, 0, mapping, current, result);
        return result;
    }

private:
    void backtrack(std::string const& digits,
        int const index,
        std::vector<std::string> const& mapping,
        std::string& current,
        std::vector<std::string>& result)
    {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        auto letters = mapping[digits[index] - '0'];

        for (auto c : letters)
        {
            current.push_back(c);
            backtrack(digits, index + 1, mapping, current, result);
            current.pop_back();
        }
    }
};