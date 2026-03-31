#include <vector>
#include <string>

class Solution {
public:
    int titleToNumber(std::string columnTitle) {
        int result = 0;

        for (auto const ch : columnTitle)
        {
            result *= 26;
            result += ch - 'A' + 1;
        }

        return result;
    }
};