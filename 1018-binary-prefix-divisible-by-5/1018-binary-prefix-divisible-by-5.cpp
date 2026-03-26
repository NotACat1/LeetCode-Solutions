#include <vector>

class Solution {
public:
    std::vector<bool> prefixesDivBy5(std::vector<int>& nums) {
        std::vector<bool> ans;
        int mod = 0;

        for (auto const& b : nums)
        {
            mod = (mod * 2 + b) % 5;
            ans.push_back(mod == 0);
        }

        return ans;
    }
};