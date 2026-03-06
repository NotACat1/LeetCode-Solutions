#include <vector>
#include <algorithm>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        return std::distance(std::begin(nums), 
            std::lower_bound(std::begin(nums), std::end(nums), target));
    }
};