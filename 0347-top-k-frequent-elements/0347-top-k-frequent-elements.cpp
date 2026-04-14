#include <vector>
#include <queue>
#include <functional>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        int n = nums.size();

        std::unordered_map<int, int> counts;
        for (auto num : nums) {
            counts[num]++;
        }

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;
        for (const auto& [num, count] : counts) {
            minHeap.push(std::pair(count, num));

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        std::vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};