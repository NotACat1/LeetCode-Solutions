#include <array>
#include <string>

class Solution {
public:
    int nextBeautifulNumber(int n) {
        int candidate = n + 1;

        while (true) {
            if (isBalanced(candidate)) {
                return candidate;
            }
            ++candidate;
        }
    }

private:
    bool isBalanced(int num) {
        std::array<int, 10> count = {};
        std::string str = std::to_string(num);

        for (auto ch : str)
        {
            int digit = ch - '0';
            ++count[digit];

            if (count[digit] > digit)
                return false;
        }

        for (int d = 0; d <= 9; ++d) {
            if (count[d] != 0 && count[d] != d) {
                return false;
            }
        }

        return true;
    }
};