#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> triangle;

        if (numRows == 0) return triangle;

        triangle.push_back({ 1 });

        for (int row = 1; row < numRows; ++row) {
            std::vector<int> prevRow = triangle[row - 1];
            std::vector<int> currentRow(row + 1);

            currentRow[0] = 1;
            currentRow[row] = 1;

            for (int col = 1; col < row; ++col)
            {
                currentRow[col] = prevRow[col - 1] + prevRow[col];
            }

            triangle.emplace_back(currentRow);
        }

        return triangle;
    }
};