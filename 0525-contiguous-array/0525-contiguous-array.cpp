#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int findMaxLength(std::vector<int>& nums) {
        std::unordered_map<int, int> sumToIndex;
        sumToIndex[0] = -1;

        int maxLen = 0;
        int currentSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                currentSum--;
            }
            else {
                currentSum++;
            }

            if (sumToIndex.contains(currentSum)) {
                maxLen = std::max(maxLen, i - sumToIndex[currentSum]);
            }
            else {
                sumToIndex[currentSum] = i;
            }
        }

        return maxLen;
    }
};