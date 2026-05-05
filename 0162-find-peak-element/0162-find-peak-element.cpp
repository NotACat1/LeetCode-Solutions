#include <vector>

class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        size_t left = 0;
        size_t right = nums.size() - 1;

        while (left < right) {
            size_t mid = left + (right - left) / 2;

            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return left;
    }
};