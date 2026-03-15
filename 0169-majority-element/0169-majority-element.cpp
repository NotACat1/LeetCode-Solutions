#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        if (nums.empty()) return -1;

        auto candidate = nums[0];
        size_t count = 1;

        for (size_t i = 1; i < nums.size(); ++i)
        {
            if (!count) {
                candidate = nums[i];
                ++count;
            }
            else if (candidate == nums[i]) {
                ++count;
            }
            else {
                --count;
            }
        }

        return candidate;
    }
};