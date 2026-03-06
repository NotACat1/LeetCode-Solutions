#include <vector>

class Solution {
public:
    int maximumEnergy(std::vector<int>& energy, int k) {
        int n = energy.size();
        std::vector<int> dp(n);

        int maxEnergy = INT_MIN;

        for (int i = n - 1; i >= 0; --i)
        {
            dp[i] = energy[i];

            if (i + k < n) {
                dp[i] += dp[i + k];
            }

            maxEnergy = std::max(maxEnergy, dp[i]);
        }

        return maxEnergy;
    }
};