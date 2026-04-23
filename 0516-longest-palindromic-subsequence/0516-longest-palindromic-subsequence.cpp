#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int longestPalindromeSubseq(std::string s) {
        size_t n = s.length();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

        for (size_t i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for (size_t len = 2; len <= n; len++) {
            for (size_t i = 0; i <= n - len; i++) {
                size_t j = i + len - 1;

                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else {
                    dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};