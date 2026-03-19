#include <string>

class Solution {
public:
    bool hasSameDigits(std::string s) {
        if (s.size() < 2) return true;

        while (s.size() > 2) {
            std::string temp = "";

            for (size_t i = 0; i < s.size() - 1; ++i) {
                auto a = static_cast<int>(s[i] - '0');
                auto b = static_cast<int>(s[i + 1] - '0');
                temp += static_cast<char>((a + b) % 10) + '0';
            }
            s = temp;
        }

        return s[0] == s[1];
    }
};