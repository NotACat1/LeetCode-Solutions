class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        std::vector<int> row_counts(m, 0);
        std::vector<int> col_counts(n, 0);
        
        for (const auto& index : indices) {
            row_counts[index[0]]++;
            col_counts[index[1]]++;
        }
        
        int odd_rows = 0;
        for (int r : row_counts) {
            if (r % 2 != 0) odd_rows++;
        }
        
        int odd_cols = 0;
        for (int c : col_counts) {
            if (c % 2 != 0) odd_cols++;
        }
        
        return odd_rows * (n - odd_cols) + (m - odd_rows) * odd_cols;
    }
};