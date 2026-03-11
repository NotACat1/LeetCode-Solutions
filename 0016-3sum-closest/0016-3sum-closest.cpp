#include <vector>
#include <algorithm>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int n = nums.size();
        std::sort(std::begin(nums), std::end(nums));

        int closestSum = nums[0] + nums[1] + nums[2];
        int minDiff = abs(closestSum - target);

        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            int minPossible = nums[i] + nums[left] + nums[left + 1];
            if (minPossible > target) {
                int diff = abs(minPossible - target);
                if (diff < minDiff) {
                    minDiff = diff;
                    closestSum = minPossible;
                }
                continue;
            }

            int maxPossible = nums[i] + nums[right] + nums[right - 1];
            if (maxPossible < target) {
                int diff = abs(maxPossible - target);
                if (diff < minDiff) {
                    minDiff = diff;
                    closestSum = maxPossible;
                }
                continue;
            }

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                if (currentSum == target) {
                    return currentSum;
                }

                int currentDiff = abs(currentSum - target);
                if (currentDiff < minDiff) {
                    minDiff = currentDiff;
                    closestSum = currentSum;
                }

                if (currentSum < target) {
                    ++left;
                }
                else {
                    --right;
                }
            }
        }

        return closestSum;
    }
};