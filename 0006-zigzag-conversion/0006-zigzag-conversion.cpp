#include <string>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1 || s.length() <= static_cast<size_t>(numRows)) {
             return s;
        }

        std::vector<std::string> rows(numRows);
        size_t currentRow = 0;
        bool goingDown = false;

        for (const auto ch : s) {
            rows[currentRow] += ch;

            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

            currentRow += goingDown ? 1 : -1;
        }

        std::string result;
        for (const auto& row : rows) {
            result += row;
        }

        return result;
    }
};