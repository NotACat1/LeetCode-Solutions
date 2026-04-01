#include <string>
#include <array>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) return false;

        std::array<int, 26> count = { 0 };

        for (auto const ch : s)
        {
            ++count[ch - 'a'];
        }

        for (auto const ch : t)
        {
            if (--count[ch - 'a'] < 0) return false;
        }

        return true;
    }
};