#include <cmath>

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;

        double res = std::log10(n) / std::log10(3);

        return std::abs(res - std::round(res)) < 1e-10;
    }
};