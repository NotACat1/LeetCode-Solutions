#include <vector>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());

        int jump = 0;
        int currentEnd = 0;
        int farthest = 0;

        for (int i = 0; i < n - 1; i++) {
            farthest = std::max(farthest, i + nums[i]);

            if (i == currentEnd) {
                jump++;
                currentEnd = farthest;

                if (currentEnd >= n - 1) break;
            }
        }

        return jump;
    }
};