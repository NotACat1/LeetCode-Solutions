#include <vector>
#include <numeric>

class Solution {
public:
    int maxSubarrays(std::vector<int>& nums) {
        int totalAnd = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            totalAnd &= nums[i];
        }

        if (totalAnd > 0) {
            return 1;
        }

        int count = 0;
        int currentAnd = -1;

        for (int num : nums) {
            if (currentAnd == -1) {
                currentAnd = num;
            } else {
                currentAnd &= num;
            }

            if (currentAnd == 0) {
                count++;
                currentAnd = -1;
            }
        }

        return count;
    }
};