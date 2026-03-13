#include <vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        if (nums.empty()) return nullptr;

        int mid = nums.size() / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        std::vector<int> left(std::begin(nums), std::begin(nums) + mid);
        std::vector<int> right(std::begin(nums) + mid + 1, std::end(nums));

        root->left  = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);

        return root;
    }
};