#include <vector>
#include <string>

class Solution {
public:
    int minDeletionSize(std::vector<std::string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int result = 0;

        for (int col = 0; col < m; col++) {
            for (int row = 0; row < n - 1; row++) {
                if (strs[row][col] > strs[row + 1][col]) {
                    result++;
                    break;
                }
            }
        }

        return result;
    }
};