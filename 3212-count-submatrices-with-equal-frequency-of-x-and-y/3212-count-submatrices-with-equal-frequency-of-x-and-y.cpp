#include <vector>

class Solution {
public:
    int numberOfSubmatrices(std::vector<std::vector<char>>& grid) {
        auto n = grid.size();
        auto m = grid[0].size();

        std::vector< std::vector<int>> pref_x(n, std::vector<int>(m, 0));
        std::vector< std::vector<int>> pref_y(n, std::vector<int>(m, 0));

        int result = 0;

        for (size_t i = 0; i < n; ++i)
        {
            for (size_t j = 0; j < m; ++j)
            {
                auto is_x = grid[i][j] == 'X';
                auto is_y = grid[i][j] == 'Y';

                if (is_x)
                    ++pref_x[i][j];

                if (is_y)
                    ++pref_y[i][j];

                if (i > 0)
                {
                    pref_x[i][j] += pref_x[i - 1][j];
                    pref_y[i][j] += pref_y[i - 1][j];
                }

                if (j > 0)
                {
                    pref_x[i][j] += pref_x[i][j - 1];
                    pref_y[i][j] += pref_y[i][j - 1];
                }

                if (i > 0 && j > 0)
                {
                    pref_x[i][j] -= pref_x[i - 1][j - 1];
                    pref_y[i][j] -= pref_y[i - 1][j - 1];
                }

                if (pref_x[i][j] != 0 && pref_x[i][j] == pref_y[i][j])
                    ++result;
            }
        }

        return result;
    }
};