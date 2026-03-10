#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        if (height.empty()) return 0;

        size_t left = 0;
        size_t right = height.size() - 1;
        int maxSquare = 0;

        while (left < right) {
            size_t w = right - left;
            int h = std::min(height[left], height[right]);

            int square = w * h;
            maxSquare = std::max(maxSquare, square);

            if (height[left] > height[right]) {
                --right;
            }
            else {
                ++left;
            }
        }

        return maxSquare;
    }
};