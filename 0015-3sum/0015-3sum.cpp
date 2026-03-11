#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        int n = nums.size();

        if (n < 3) return result;

        std::sort(begin(nums), end(nums));

        if (nums[0] > 0) return result;

        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            if (nums[i] > 0) break;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({ nums[i], nums[left], nums[right] });

                    int leftVal = nums[left];
                    int rightVal = nums[right];

                    while (left < right && nums[left] == leftVal) ++left;
                    while (left < right && nums[right] == rightVal) --right;
                }
                else if (sum < 0) {
                    ++left;
                }
                else {
                    --right;
                }
            }
        }

        return result;
    }
};