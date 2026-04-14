#include <vector>
#include <queue>
#include <tuple>
#include <functional>

class Solution {
private:
    using Element = std::tuple<int, int, int>;

    struct Compare {
        bool operator()(const Element& a, const Element& b) {
            return get<0>(a) > get<0>(b);
        }
    };

public:
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        std::vector<std::vector<int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0) return result;

        std::priority_queue<Element, std::vector<Element>, Compare> minHeap;

        for (int i = 0; i < std::min(static_cast<int>(nums1.size()), k); i++) {
            minHeap.push({ nums1[i] + nums2[0], i, 0 });
        }

        while (k-- > 0 && !minHeap.empty()) {
            const auto [sum, i, j] = minHeap.top();
            minHeap.pop();

            result.push_back({ nums1[i], nums2[j] });

            if (j + 1 < nums2.size()) {
                minHeap.push({ nums1[i] + nums2[j + 1], i, j + 1 });
            }
        }

        return result;
    }
};