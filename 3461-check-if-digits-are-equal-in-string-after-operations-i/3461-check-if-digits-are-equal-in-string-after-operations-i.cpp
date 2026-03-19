#include <vector>
#include <string>

class Solution {
public:
    bool hasSameDigits(std::string s) {
        auto n = s.size();
        std::vector<int> row(n - 1, 0);
        row[0] = 1;

        for (int i = 1; i <= n - 2; i++) {
            for (int j = i; j > 0; j--) {
                row[j] = (row[j] + row[j - 1]) % 10;
            }
        }

        int left = 0, right = 0;

        for (int i = 0; i < n - 1; i++) {
            int digit = s[i] - '0';
            left = (left + row[i] * digit) % 10;
        }

        for (int i = 0; i < n - 1; i++) {
            int digit = s[i + 1] - '0';
            right = (right + row[i] * digit) % 10;
        }

        return left == right;
    }
};