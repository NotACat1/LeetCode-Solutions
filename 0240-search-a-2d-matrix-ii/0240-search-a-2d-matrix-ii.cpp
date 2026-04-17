#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        const int rows = static_cast<int>(matrix.size());
        const int cols = static_cast<int>(matrix[0].size());

        int row = 0;
        int col = cols - 1;

        while (row < rows && col >= 0) {
            const int current = matrix[row][col];

            if (current == target) {
                return true;
            } 
            else if (current > target) {
                col--;
            }
            else {
                row++;
            }
        }

        return false;
    }
};