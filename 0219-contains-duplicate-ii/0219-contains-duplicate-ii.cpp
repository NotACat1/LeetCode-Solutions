#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_set<int> window;

        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (window.contains(nums[i])) {
                return true;
            }

            window.insert(nums[i]);

            if (window.size() > k) {
                window.erase(nums[i - k]);
            }
        }

        return false;
    }
};