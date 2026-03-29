#include <vector>

class Solution {
public:
    std::vector<int> minBitwiseArray(std::vector<int>& nums) {
        std::vector<int> result;

        for (auto num : nums)
        {
            int bit = 1;
            while (num & bit) {
                bit <<= 1;
            }

            if (bit == 1) {
                result.push_back(-1);
            }
            else {
                result.push_back(num - (bit >> 1));
            }
        }

        return result;
    }
};