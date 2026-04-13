#include <vector>

class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        int currentSum = 0;
        for (int i = 0; i < k; ++i) {
            currentSum += nums[i];
        }

        int maxSum = currentSum;

        for (size_t i = k; i < nums.size(); i++)
        {
            currentSum += nums[i] - nums[i - k];
            maxSum = std::max(maxSum, currentSum);
        }

        return static_cast<double>(maxSum) / k;
    }
};