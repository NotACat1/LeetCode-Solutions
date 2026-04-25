#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set set1(nums1.begin(), nums1.end());
        std::vector<int> result;

        for (const auto num : nums2) {
            if (set1.contains(num)) {
                result.push_back(num);
                set1.erase(num);
            }
        }

        return result;
    }
};