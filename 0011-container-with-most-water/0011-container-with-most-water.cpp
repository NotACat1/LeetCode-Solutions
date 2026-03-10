#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        if (height.empty()) return 0;

        int left = 0;
        int right = height.size() - 1;
        long maxSquare = 0;

        while (left < right) {
            int w = right - left;
            int h = std::min(height[left], height[right]);

            long square = w * h;
            maxSquare = maxSquare > square ? maxSquare : square;

            height[left] > height[right] ? --right : ++left;
        }

        return maxSquare;
    }
};