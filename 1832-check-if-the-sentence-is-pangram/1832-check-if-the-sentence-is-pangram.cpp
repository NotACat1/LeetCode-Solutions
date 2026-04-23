#include <string>
#include <vector>

class Solution {
public:
    bool checkIfPangram(std::string sentence) {
        if (sentence.length() < 26) return false;

        std::vector seen(26, false);

        for (const auto ch : sentence) {
            seen[ch - 'a'] = true;
        }

        for (const auto is_present : seen) {
            if (!is_present) return false;
        }

        return true;
    }
};