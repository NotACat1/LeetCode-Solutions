#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1) return s;

        auto size = std::min(numRows, static_cast<int>(s.length()));
        std::vector<std::string> rows(size);

        int currentRow = 0;
        bool goingDown = false;

        for (const auto c : s) {
            rows[currentRow] += c;

            if (currentRow == 0 || currentRow == numRows - 1)
                goingDown = !goingDown;

            goingDown ? ++currentRow : --currentRow;
        }

        std::string result;
        for (const auto& row : rows) {
            result += row;
        }

        return result;
    }
};