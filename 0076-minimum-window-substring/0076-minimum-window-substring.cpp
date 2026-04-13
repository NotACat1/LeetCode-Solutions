#include <string>
#include <unordered_map>
#include <climits>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.empty() || t.empty()) return "";

        std::unordered_map<char, int> targetCounts;
        for (const auto ch : t) {
            targetCounts[ch]++;
        }

        std::unordered_map<char, int> windowCounts;

        int have = 0;
        int need = targetCounts.size();
        int resLen = INT_MAX;
        int resStart = 0;

        int left = 0;
        for (int right = 0; right < s.length(); ++right) {
            const auto ch = s[right];
            windowCounts[ch]++;

            if (targetCounts.contains(ch) && windowCounts[ch] == targetCounts[ch]) {
                have++;
            }

            while (have == need) {
                if (right - left + 1 < resLen) {
                    resLen = right - left + 1;
                    resStart = left;
                }

                const auto leftChar = s[left];
                windowCounts[leftChar]--;

                if (targetCounts.contains(leftChar) && windowCounts[leftChar] < targetCounts[leftChar]) {
                    have--;
                }

                left++;
            }
        }

        return (resLen == INT_MAX) ? "" : s.substr(resStart, resLen);
    }
};