#include <vector>
#include <numeric>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        return std::reduce(std::begin(nums), std::end(nums), 0,
            [](int a, int b) { return a ^ b; });
    }
};