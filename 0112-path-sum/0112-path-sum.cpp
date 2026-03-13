#include <stack>
#include <utility>

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root || root->val > targetSum) return false;

        std::stack<std::pair<TreeNode*, int>> st;        
        st.push({ root, root->val });

        while (!st.empty()) {
            auto [node, currentSum] = st.top();
            st.pop();

            if (!node->left && !node->right && currentSum == targetSum) 
                return true;

            if (node->right && currentSum + node->right->val <= targetSum) 
                st.push({ node->right, currentSum + node->right->val });

            if (node->left && currentSum + node->left->val <= targetSum)
                st.push({ node->left, currentSum + node->left->val });
        }

        return false;
    }
};