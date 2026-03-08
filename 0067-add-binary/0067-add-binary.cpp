#include <string>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string result;

        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            carry += (i >= 0) ? a[i--] - '0' : 0;
            carry += (j >= 0) ? b[j--] - '0' : 0;

            result = static_cast<char>(carry % 2 + '0') + result;
            carry /= 2;
        }

        return result;
    }
};