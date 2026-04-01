#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        std::vector<std::string> result;
        auto n = nums.size();

        if (n == 0) return result;

        auto start = nums[0];

        for (size_t i = 1; i < n; ++i)
        {
            if (nums[i] != nums[i - 1] + 1) {
                if (start == nums[i - 1])
                {
                    result.push_back(std::to_string(start));
                }
                else {
                    result.push_back(std::to_string(start) + "->" + std::to_string(nums[i - 1]));
                }
                start = nums[i];
            }
        }

        if (start == nums.back())
        {
            result.push_back(std::to_string(start));
        }
        else {
            result.push_back(std::to_string(start) + "->" + std::to_string(nums.back()));
        }
        
        return result;
    }
};