#include <unordered_set>

class Solution {
public:
    std::vector<int> getSneakyNumbers(std::vector<int>& nums) {
        std::unordered_set<int> seen;
        std::vector<int> result;

        for (int num : nums) {
            if (seen.count(num)) {
                result.push_back(num);
            }
            else {
                seen.insert(num);
            }
        }

        return result;
    }
};