#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";

        int start = 0;
        int maxLength = 1;

        for (int i = 0; i < s.length(); ++i)
        {
            auto len1 = expandAroundCenter(s, i, i);
            auto len2 = expandAroundCenter(s, i, i + 1);

            auto len = std::max(len1, len2);
            if (len > maxLength) {
                maxLength = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLength);
    }
private:
    int expandAroundCenter(const std::string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};