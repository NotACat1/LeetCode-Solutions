#include <vector>
#include <numeric>
#include <algorithm>
#include <algorithm>

class Solution {
public:
    int minimumBoxes(std::vector<int>& apple, std::vector<int>& capacity) {
        auto total = std::accumulate(apple.begin(), apple.end(), 0u);
        std::sort(capacity.begin(), capacity.end(), std::greater());

        auto used = 0u;
        auto sumCapacity = 0u;

        for (auto const& cap : capacity)
        {
            sumCapacity += cap;
            ++used;

            if (sumCapacity >= total)
            {
                return used;
            }                
        }

        return used;
    }
};