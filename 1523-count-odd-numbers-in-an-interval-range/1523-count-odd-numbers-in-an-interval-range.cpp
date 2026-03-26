class Solution {
public:
    int countOdds(int low, int high) {
        auto n = high - low + 1;
        auto result = static_cast<int>(n / 2);
        if (low % 2 == 1 && high % 2 == 1) {
            ++result;
        }
        return result;
    }
};