#include <vector>
#include <unordered_map>
#include <set>

class Solution {
public:
    std::vector<int> avoidFlood(std::vector<int>& rains) {
        auto n = rains.size();
        std::vector<int> ans(n, -1);
        std::unordered_map<int, size_t> fullLake;
        std::set<size_t> dryDays;

        for (size_t i = 0; i < n; ++i)
        {
            if (rains[i] == 0) {
                dryDays.insert(i);
                ans[i] = 1;
            }
            else {
                auto lake = rains[i];

                if (fullLake.count(lake)) {
                    auto lastRainDay = fullLake[lake];

                    auto it = dryDays.upper_bound(lastRainDay);
                    if (it == std::end(dryDays)) {
                        return {};
                    }

                    ans[*it] = lake;
                    dryDays.erase(it);
                }

                fullLake[lake] = i;
            }
        }

        return ans;
    }
};