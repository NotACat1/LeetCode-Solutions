#include <vector>
#include <algorithm>
#include <functional>

class Solution {
public:
    int largestSubmatrix(std::vector<std::vector<int>>& matrix) {
        auto m = matrix.size();
        auto n = matrix[0].size();

        std::vector<int> height(n, 0);
        int ans = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j])
                    ++height[j];
                else
                    height[j] = 0;
            }

            std::vector<int> sorted = height;
            std::sort(std::begin(sorted), std::end(sorted), std::greater<int>());

            for (int k = 0; k < n; ++k) {
                int area = sorted[k] * (k + 1);
                ans = std::max(ans, area);
            }
        }

        return  ans;
    }
};