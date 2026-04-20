#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, size_t> seen;

        for (size_t i = 0; i < nums.size(); i++) {
            auto complement = target - nums[i];

            if (auto it = seen.find(complement); it != seen.end()) {
                return { static_cast<int>(it->second), static_cast<int>(i) };
            }

            seen[nums[i]] = i;
        }

        return {};
    }
};