#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        auto carry = 1;

        for (auto it = std::rbegin(digits); it != std::rend(digits); ++it) {
            auto sum = *it + carry;
            *it = sum % 10;
            carry = sum / 10;

            if (carry == 0) break;
        }

        if (carry) {
            digits.insert(std::begin(digits), carry);
        }

        return digits;
    }
};