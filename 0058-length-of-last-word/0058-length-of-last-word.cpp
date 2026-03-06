#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        if (s.empty()) return 0;

        int length = 0;
        int i = s.length() - 1;

        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};