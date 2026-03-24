#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> constructProductMatrix(std::vector<std::vector<int>>& grid) {
        const int MOD = 12345;
        int n = grid.size();
        if (n == 0) return {};
        int m = grid[0].size();

        std::vector<std::vector<int>> p(n, std::vector<int>(m));

        std::vector<int> row_prod(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                row_prod[i] = (row_prod[i] * (grid[i][j] % MOD)) % MOD;
            }
        }

        std::vector<int> prefix_row_prod(n + 1, 1), suffix_row_prod(n + 1, 1);
        for (int i = 0; i < n; ++i) {
            prefix_row_prod[i + 1] = (prefix_row_prod[i] * row_prod[i]) % MOD;
        }
        for (int i = n - 1; i >= 0; --i) {
            suffix_row_prod[i] = (suffix_row_prod[i + 1] * row_prod[i]) % MOD;
        }

        for (int i = 0; i < n; ++i) {
            std::vector<int> prefix_in_row(m + 1, 1), suffix_in_row(m + 1, 1);
            for (int j = 0; j < m; ++j) {
                prefix_in_row[j + 1] = (prefix_in_row[j] * (grid[i][j] % MOD)) % MOD;
            }
            for (int j = m - 1; j >= 0; --j) {
                suffix_in_row[j] = (suffix_in_row[j + 1] * (grid[i][j] % MOD)) % MOD;
            }

            for (int j = 0; j < m; ++j) {
                int product_except_row_i = (prefix_row_prod[i] * suffix_row_prod[i + 1]) % MOD;
                int product_except_self_in_row = (prefix_in_row[j] * suffix_in_row[j + 1]) % MOD;
                p[i][j] = (product_except_row_i * product_except_self_in_row) % MOD;
            }
        }

        return p;
    }
};