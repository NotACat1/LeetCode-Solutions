class Solution {
public:
    int countValidSelections(std::vector<int>& nums) {
        auto n = nums.size();

        long long total = 0;
        for (int x : nums) total += x;

        long long left = 0;
        int ans = 0;

        for (size_t i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                long long right = total - left;

                if (left == right) {
                    ans += 2;
                }
                else if (abs(left - right) == 1) {
                    ans += 1;
                }
            }
            left += nums[i];
        }

        return ans;
    }
};