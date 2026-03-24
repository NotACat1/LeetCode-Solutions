#include <vector>

class Solution {
public:
    bool kLengthApart(std::vector<int>& nums, int k) {
        int last_one_index = -1;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                if (last_one_index != -1) {
                    int distance = i - last_one_index - 1;
                    if (distance < k) {
                        return false;
                    }
                }
                last_one_index = i;
            }
        }

        return true;
    }
};