#include <vector>

class NumArray {
private:
    std::vector<int> prefixSums;

public:
    NumArray(std::vector<int>& nums) {
        auto n = nums.size();
        prefixSums.resize(n + 1, 0);

        for (size_t i = 0; i < n; i++)
        {
            prefixSums[i + 1] = prefixSums[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return prefixSums[right + 1] - prefixSums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */