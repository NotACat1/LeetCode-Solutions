#include <string>
#include <regex>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        std::regex reg(p);
        return std::regex_match(s, reg);
    }
};