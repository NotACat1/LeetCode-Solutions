#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        auto n = nums.size() + 1;
        auto expected = n * (n - 1) / 2;
        
        for (const auto num : nums)
        {
            expected -= num;
        }

        return expected;
    }
};