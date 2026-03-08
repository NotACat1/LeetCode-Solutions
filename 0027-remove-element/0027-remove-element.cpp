#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int left = 0;
        int right = nums.size() - 1;
        int count = 0;

        while (left <= right) {
            if (nums[left] == val) {
                std::swap(nums[left], nums[right]);
                --right;
            }
            else {
                ++left;
                ++count;
            }
        }

        return count;
    }
};