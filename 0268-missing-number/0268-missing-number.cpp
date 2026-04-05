#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        auto n = nums.size();
        auto result = n;

        for (size_t i = 0; i < n; i++)
        {
            result ^= i;
            result ^= nums[i];
        }

        return result;
    }
};