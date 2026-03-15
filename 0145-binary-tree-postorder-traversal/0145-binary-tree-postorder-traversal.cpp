#include <vector>
#include <stack>
#include <algorithm>

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
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if (root == nullptr) return result;

        std::stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            auto current = st.top();
            st.pop();

            result.push_back(current->val);
            if (current->left)  st.push(current->left);
            if (current->right) st.push(current->right);
        }

        std::reverse(std::begin(result), std::end(result));

        return result;
    }
};