#include <unordered_map>
#include <string>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        if (s.size() != t.size()) return false;

        std::unordered_map<char, char> m1;
        std::unordered_map<char, char> m2;

        for (size_t i = 0; i < s.size(); ++i)
        {
            auto const ch1 = s[i];
            auto const ch2 = t[i];

            // s -> t
            if (m1.count(ch1)) {
                if (m1[ch1] != ch2) return false;
            }
            else {
                m1[ch1] = ch2;
            }

            // t -> s
            if (m2.count(ch2)) {
                if (m2[ch2] != ch1) return false;
            }
            else {
                m2[ch2] = ch1;
            }
        }

        return true;
    }
};