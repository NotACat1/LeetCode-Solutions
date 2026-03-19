#include <vector>
#include <utility>

class Solution {
public:
    int numberOfSubmatrices(std::vector<std::vector<char>>& grid) {
        auto n = grid.size();
        auto m = grid[0].size();

        std::vector<std::pair<bool, int>> diff(m, { false, 0 });
        int result = 0;

        for (auto const& row : grid)
        {
            int sum = 0;
            bool has_x_row = false;

            for (size_t j = 0; j < m; ++j)
            {
                if (row[j] == 'X') {
                    has_x_row = true;
                    ++sum;
                }
                else if (row[j] == 'Y') {
                    --sum;
                }

                auto& [has_x, count_diff] = diff[j];
                
                has_x |= has_x_row;
                count_diff += sum;

                if (has_x && count_diff == 0) {
                    result++;
                }
            }
        }

        return result;
    }
};