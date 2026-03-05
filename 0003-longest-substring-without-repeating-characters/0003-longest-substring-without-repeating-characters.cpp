#include <string>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::unordered_map<char, int> lastSeen;
        int maxLength = 0;
        int start = 0;

        for (int end = 0; end < s.length(); ++end)
        {
            char current = s[end];

            if (auto it = lastSeen.find(current);
                it != lastSeen.end() &&
                lastSeen[current] >= start)
            {
                start = it->second + 1;
            }

            lastSeen[current] = end;
            maxLength = std::max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};