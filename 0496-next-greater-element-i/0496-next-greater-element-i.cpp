#include <vector>
#include <stack>
#include <unordered_map>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> next_greater;
        std::stack<int> s;

        for (const auto num : nums2) {
            while (!s.empty() && num > s.top()) {
                next_greater[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }

        std::vector<int> result;
        for (const auto num : nums1) {
            if (next_greater.count(num)) {
                result.push_back(next_greater[num]);
            }
            else {
                result.push_back(-1);
            }
        }

        return result;
    }
};