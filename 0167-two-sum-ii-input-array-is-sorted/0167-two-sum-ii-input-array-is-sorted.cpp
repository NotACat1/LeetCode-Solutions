#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int left  = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            auto currentSum = numbers[left] + numbers[right];

            if (currentSum == target) {
                return { ++left, ++right };
            }

            if (currentSum < target) {
                left++;
            }
            else {
                right--;
            }
        }

        return {};
    }
};