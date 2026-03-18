#include <vector>
#include <string>

class Solution {
public:
    int finalValueAfterOperations(std::vector<std::string>& operations) {
        int result = 0;
        for (auto& operation : operations) {
            if (operation[1] == '+')
            {
                ++result;
            }
            else
            {
                --result;
            }
        }
        return result;
    }
};