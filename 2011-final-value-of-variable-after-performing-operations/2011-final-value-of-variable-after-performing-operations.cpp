#include <vector>
#include <string>

class Solution {
public:
    int finalValueAfterOperations(std::vector<std::string>& operations) {
        int result = 0;
        for (auto& operation : operations) {
            if (operation == "++X" || operation == "X++") ++result;
            if (operation == "--X" || operation == "X--") --result;
        }
        return result;
    }
};