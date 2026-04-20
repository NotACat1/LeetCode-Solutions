#include <string>

class Solution {
private:
    int expandAroundCenter(const std::string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }

        return right - left - 1;
    }

public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";

        int maxLength = 0;
        int start = 0;

        for (size_t i = 0; i < s.length(); i++) {
            int length1 = expandAroundCenter(s, i, i);
            int length2 = expandAroundCenter(s, i, i + 1);

            int length = std::max(length1, length2);

            if (length > maxLength) {
                maxLength = length;
                start = i - (length - 1) / 2;
            }
        }

        return s.substr(start, maxLength);
    }
};