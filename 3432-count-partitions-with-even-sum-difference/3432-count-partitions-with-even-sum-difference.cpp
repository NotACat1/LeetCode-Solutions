#include <vector>
#include <numeric>

class Solution {
public:
    int countPartitions(std::vector<int>& nums) {
        auto sum = std::accumulate(nums.begin(), nums.end(), 0LL);

        return (sum % 2 == 0) ? nums.size() - 1 : 0;
    }
};