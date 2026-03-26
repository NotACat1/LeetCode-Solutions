#include <vector>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        int remain = 0;

        for (auto const& num : nums)
        {
            remain = (remain + (num % k)) % k;
        }

        return remain;
    }
};