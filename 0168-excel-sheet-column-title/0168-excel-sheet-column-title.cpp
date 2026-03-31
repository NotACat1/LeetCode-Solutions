#include <string>

class Solution {
public:
    std::string convertToTitle(int columnNumber) {
        std::string result;

        while (columnNumber > 0) {
            columnNumber--;
            char currentChar = 'A' + (columnNumber % 26);
            result = currentChar + result;
            
            columnNumber /= 26;
        }

        return result;
    }
};