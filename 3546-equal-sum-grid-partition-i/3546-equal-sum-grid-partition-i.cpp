class Solution {
public:
    bool canPartitionGrid(std::vector<std::vector<int>>& grid) {
        size_t m = grid.size();
        size_t n = grid[0].size();

        std::vector<long long> row_sums(m, 0);
        long long total = 0;
        
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                row_sums[i] += grid[i][j];
            }
            total += row_sums[i];
        }

        if (total % 2 != 0) {
            return false;
        }

        long long target = total / 2;

        long long row_sum = 0;
        for (size_t i = 0; i < m - 1; i++) {
            row_sum += row_sums[i];
            if (row_sum == target) {
                return true;
            }
        }

        std::vector<long long> col_sums(n, 0);
        for (size_t j = 0; j < n; j++) {
            for (size_t i = 0; i < m; i++) {
                col_sums[j] += grid[i][j];
            }
        }
        
        long long col_sum = 0;
        for (size_t j = 0; j < n - 1; j++) {
            col_sum += col_sums[j];
            if (col_sum == target) {
                return true;
            }
        }

        return false;
    }
};