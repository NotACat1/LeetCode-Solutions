#include <vector>

class Solution {
public:
    int countNegatives(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int result = 0;
        int left_barrier = 0;

        for (int i = n - 1; i >= 0 && left_barrier != m; --i) {
            for (int j = m - 1; j >= left_barrier; --j) {
                if (grid[i][j] >= 0) {
                    left_barrier = j + 1;
                    break;
                }
                result++;
            }
        }

        return result;
    }
};