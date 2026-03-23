#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProductPath(std::vector<std::vector<int>>& grid) {
        const long long MOD = 1e9 + 7;
        
        int m = grid.size();
        int n = grid[0].size();
        
        std::vector<std::vector<long long>> maxDp(m, std::vector<long long>(n));
        std::vector<std::vector<long long>> minDp(m, std::vector<long long>(n));
        
        maxDp[0][0] = minDp[0][0] = grid[0][0];
        
        // Первая строка
        for (int j = 1; j < n; j++) {
            maxDp[0][j] = minDp[0][j] = maxDp[0][j-1] * grid[0][j];
        }
        
        // Первый столбец
        for (int i = 1; i < m; i++) {
            maxDp[i][0] = minDp[i][0] = maxDp[i-1][0] * grid[i][0];
        }
        
        // Остальная матрица
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long long val = grid[i][j];
                
                long long candidates[] = {
                    maxDp[i-1][j] * val,
                    minDp[i-1][j] * val,
                    maxDp[i][j-1] * val,
                    minDp[i][j-1] * val
                };
                
                maxDp[i][j] = *std::max_element(candidates, candidates + 4);
                minDp[i][j] = *std::min_element(candidates, candidates + 4);
            }
        }
        
        long long result = maxDp[m-1][n-1];
        
        if (result < 0) return -1;
        return result % MOD;
    }
};