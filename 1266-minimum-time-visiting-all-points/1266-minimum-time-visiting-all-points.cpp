#include <vector>

class Solution {
public:
    int minTimeToVisitAllPoints(std::vector<std::vector<int>>& points) {
        int total = 0;

        for (size_t i = 1; i < points.size(); ++i) {
            auto dx = abs(points[i][0] - points[i - 1][0]);
            auto dy = abs(points[i][1] - points[i - 1][1]);
            total += std::max(dx, dy);
        }

        return total;
    }
};