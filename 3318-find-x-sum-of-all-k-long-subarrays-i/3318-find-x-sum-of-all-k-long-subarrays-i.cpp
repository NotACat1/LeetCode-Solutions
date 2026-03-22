class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        size_t const n = nums.size();
        std::vector<int> ans;

        for (size_t i = 0; i + k <= n; ++i) {
            std::unordered_map<int, int> freq;

            for (size_t j = i; j < i + k; ++j) {
                ++freq[nums[j]];
            }

            std::vector<std::pair<int, int>> v;
            v.reserve(freq.size());

            for (auto const& [value, f] : freq) {
                v.emplace_back(f, value);
            }

            std::sort(v.begin(), v.end(),
                [](auto const& a, auto const& b) {
                    if (a.first != b.first)
                        return a.first > b.first;
                    return a.second > b.second;
                });

            size_t const limit =
                std::min(static_cast<size_t>(x), v.size());

            int sum = 0;

            for (size_t t = 0; t < limit; ++t) {
                auto const& [f, value] = v[t];
                sum += f * value;
            }

            ans.push_back(sum);
        }

        return ans;
    }
};