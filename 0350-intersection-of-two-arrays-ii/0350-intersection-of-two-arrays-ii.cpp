#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }

        std::unordered_map<int, int> counts;
        for (const auto num : nums1) {
            counts[num]++;
        }

        std::vector<int> result;
        for (const auto num : nums2) {
            if (counts.contains(num) && counts[num] > 0) {
                result.push_back(num);
                counts[num]--;
            }
        }

        return result;
    }
};