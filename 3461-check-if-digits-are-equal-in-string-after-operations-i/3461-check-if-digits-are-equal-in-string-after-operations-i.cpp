#include <vector>
#include <string>

class Solution {
public:
    bool hasSameDigits(std::string s) {
        auto n = s.length();
        std::vector<int> row(n - 1, 1);

        for (int len = 1; len < n - 1; ++len) {
            for (int j = len; j > 0; --j) {
                row[j] = (row[j] + row[j - 1]) % 10;
            }
        }

        int left = 0, right = 0;

        for (int i = 0; i < n - 1; ++i) {
            left = (left + row[i] * (s[i] - '0')) % 10;
        }

        for (int i = 0; i < n - 1; ++i) {
            right = (right + row[i] * (s[i + 1] - '0')) % 10;
        }

        return left == right;
    }
};