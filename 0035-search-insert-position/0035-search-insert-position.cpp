#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        if (nums.empty()) return 0;

        if (target <= nums[0]) return 0;
        if (target > nums.back()) return nums.size();

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};