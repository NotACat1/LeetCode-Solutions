#include <string>
#include <vector>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::vector<int> alphabet(26, 0);

        for (const auto ch : magazine) {
            alphabet[ch - 'a']++;
        }

        for (const auto ch : ransomNote) {
            if (--alphabet[ch - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};