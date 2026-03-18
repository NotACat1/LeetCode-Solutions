#include <vector>

class Solution {
public:
    int countSubmatrices(std::vector<std::vector<int>>& grid, int k) {
        auto n = grid.size();
        auto m = grid[0].size();

        int count = 0;

        for (size_t i = 0; i < n; ++i)
        {
            for (size_t j = 0; j < m; ++j)
            {
                if (i > 0) grid[i][j] += grid[i - 1][j];
                if (j > 0) grid[i][j] += grid[i][j - 1];
                if (i > 0 && j > 0) grid[i][j] -= grid[i - 1][j - 1];

                if (grid[i][j] <= k) ++count;
            }
        }

        return count;
    }
};