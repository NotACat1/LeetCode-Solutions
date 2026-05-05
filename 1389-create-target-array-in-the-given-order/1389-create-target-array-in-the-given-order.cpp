#include <vector>

class Solution {
public:
    std::vector<int> createTargetArray(std::vector<int>& nums, std::vector<int>& index) {
        auto size = nums.size();

        std::vector<int> target;
        target.reserve(size);

        for (size_t i = 0; i < size; ++i) {
            target.insert(target.begin() + index[i], nums[i]);
        }

        return target;
    }
};