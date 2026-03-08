#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        if (nums.empty()) return 0;

        size_t write = 0;

        for (size_t read = 0; read < nums.size(); ++read) {
            if (nums[read] != val) {
                nums[write] = nums[read];
                ++write;
            }
        }

        return write;
    }
};