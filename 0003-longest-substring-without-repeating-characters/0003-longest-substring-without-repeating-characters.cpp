#include <string>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, size_t> lastSeen;
        size_t maxLength = 0;
        size_t start = 0;

        for (size_t end = 0; end < s.length(); end++) {
            auto current = s[end];

            if (lastSeen.contains(current) && lastSeen[current] >= start) {
                start = lastSeen[current] + 1;
            }

            lastSeen[current] = end;
            maxLength = std::max(maxLength, end - start + 1);
        }

        return static_cast<int>(maxLength);
    }
};