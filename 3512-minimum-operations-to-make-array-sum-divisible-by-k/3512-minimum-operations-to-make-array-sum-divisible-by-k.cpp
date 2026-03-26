#include <vector>
#include <numeric>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        auto sum = std::accumulate(nums.begin(), nums.end(), 0LL);
        return sum % k;
    }
};