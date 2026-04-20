#include <string>

class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0;
        int n = s.length();
        bool isPositive = true;
        int result = 0;

        while (i < n && s[i] == ' ') {
            i++;
        }

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                isPositive = false;
            }
            i++;
        }

        while (i < n && s[i] == '0') {
            i++;
        }

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            int limit = isPositive ? 7 : 8;
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit >= limit)) {
                return isPositive ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return isPositive ? result : -result;
    }
};