#include <vector>

class Solution {
public:
    bool isOneBitCharacter(std::vector<int>& bits) {
        size_t i = 0;
        while (i < bits.size() - 1) {
            i += (bits[i] == 1) ? 2 : 1;
        }
        return i == bits.size() - 1;
    }
};