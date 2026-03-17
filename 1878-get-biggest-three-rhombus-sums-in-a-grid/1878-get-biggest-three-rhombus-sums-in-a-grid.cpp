#include <vector>
#include <set>
#include <algorithm>
#include <functional>

class Solution {
public:
    std::vector<int> getBiggestThree(std::vector<std::vector<int>>& grid) {
        auto m = grid.size();
        auto n = grid[0].size();

        std::set<int, std::greater<int>> sums;

        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                sums.insert(grid[i][j]);

                auto maxK = std::min({ i, j, m - 1 - i, n - 1 - j });

                for (size_t k = 1; k <= maxK; ++k) {
                    int sum = 0;                    

                    // top → right
                    size_t x = i - k, y = j;
                    for (size_t t = 0; t < k; ++t)
                        sum += grid[x + t][y + t];

                    // right → bottom
                    x = i, y = j + k;
                    for (size_t t = 0; t < k; ++t)
                        sum += grid[x + t][y - t];

                    // bottom → left
                    x = i + k, y = j;
                    for (size_t t = 0; t < k; ++t)
                        sum += grid[x - t][y - t];

                    // left → top
                    x = i, y = j - k;
                    for (size_t t = 0; t < k; ++t)
                        sum += grid[x - t][y + t];

                    sums.insert(sum);
                }
            }
        }

        std::vector<int> ans;
        for (auto s : sums) {
            ans.push_back(s);
            if (ans.size() == 3) break;
        }

        return ans;
    }
};