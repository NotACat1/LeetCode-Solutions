#include <vector>

class Solution {
public:
    int minimumOperations(std::vector<int>& nums) {
        int count_operations = 0;
        for (auto const& element : nums)
        {
            if (element % 3 != 0) ++count_operations;
        }
        return count_operations;
    }
};
