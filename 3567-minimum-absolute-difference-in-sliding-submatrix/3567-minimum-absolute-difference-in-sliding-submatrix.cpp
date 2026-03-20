#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> minAbsDiff(std::vector<std::vector<int>>& grid, int k) {
        auto m = grid.size();
        auto n = grid[0].size();

        std::vector<std::vector<int>> ans(m - k + 1, std::vector<int>(n - k + 1));

        for (int i = 0; i <= m - k; ++i) {
            for (int j = 0; j <= n - k; ++j) {

                std::vector<int> vals;

                for (int x = i; x < i + k; ++x)
                    for (int y = j; y < j + k; ++y)
                        vals.push_back(grid[x][y]);

                std::sort(vals.begin(), vals.end());

                int best = INT_MAX;

                for (int t = 1; t < vals.size(); ++t) {
                    if (vals[t] != vals[t - 1]) {
                        best = std::min(best, vals[t] - vals[t - 1]);
                    }
                }

                if (best == INT_MAX) best = 0;

                ans[i][j] = best;
            }
        }

        return ans;
    }
};