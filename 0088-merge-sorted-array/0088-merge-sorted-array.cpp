#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        if (m < 0 || n < 0)
            throw std::invalid_argument("m and n must be non-negative");

        if (nums1.size() < m + n)
            throw std::invalid_argument("nums1 must have a size of at least m + n");

        if (nums2.size() < n)
            throw std::invalid_argument("nums2 must have a minimum size of n");

        if (n == 0) return;

        int i = m - 1;       // Pointer to the last element  in nums1
        int j = n - 1;       // Pointer to the last element  in nums2
        int k = m + n - 1;   // Pointer to the last position in nums1

        while (i >= 0 && j >= 0)
            nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];

        while (j >= 0)
            nums1[k--] = nums2[j--];
    }
};