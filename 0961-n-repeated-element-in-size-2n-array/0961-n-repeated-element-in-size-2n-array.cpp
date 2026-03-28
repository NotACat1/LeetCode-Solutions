#include <vector>
#include <unordered_set>

class Solution {
public:
    int repeatedNTimes(std::vector<int>& nums) {
        std::unordered_set<int> seen;

        for (int x : nums) {
            if (seen.count(x)) return x;
            seen.insert(x);
        }

        return -1;
    }
};