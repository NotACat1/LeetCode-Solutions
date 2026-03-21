#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> reverseSubmatrix(
        std::vector<std::vector<int>>& grid,
        int x, int y, int k
    ) {
        for (int t = 0; t < k / 2; ++t) {
            int row1 = x + t;
            int row2 = x + k - 1 - t;

            for (int j = y; j < y + k; ++j) {
                std::swap(grid[row1][j], grid[row2][j]);
            }
        }

        return grid;
    }
};