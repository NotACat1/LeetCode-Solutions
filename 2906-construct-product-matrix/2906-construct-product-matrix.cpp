#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> constructProductMatrix(std::vector<std::vector<int>>& grid) {
        auto const n = grid.size();
        auto const m = grid[0].size();
        int const MOD = 12345;

        std::vector<std::vector<int>> p(n, std::vector<int>(m, 1));

        long long pref = 1;
        for (int i = 0; i < n * m; ++i) {
            int r = i / m;
            int c = i % m;

            p[r][c] = pref;
            pref = (pref * grid[r][c]) % MOD;
        }

        long long suff = 1;
        for (int i = n * m - 1; i >= 0; --i) {
            int r = i / m;
            int c = i % m;

            p[r][c] = (p[r][c] * suff) % MOD;
            suff = (suff * grid[r][c]) % MOD;
        }

        return p;
    }
};