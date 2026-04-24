#include <vector>
#include <unordered_map>

class Solution {
public:
    bool isPossibleToSplit(std::vector<int>& nums) {
        std::unordered_map<int, int> counts;
        
        for (int num : nums) {
            counts[num]++;
            
            if (counts[num] > 2) {
                return false;
            }
        }
        
        return true;
    }
};