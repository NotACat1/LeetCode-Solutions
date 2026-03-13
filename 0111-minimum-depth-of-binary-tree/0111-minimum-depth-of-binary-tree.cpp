#include <queue>

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
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        std::queue<TreeNode*> que;
        que.push(root);
        int depth = 1;

        while (!que.empty())
        {
            auto levelSize = que.size();

            for (size_t i = 0; i < levelSize; ++i) {
                auto node = que.front();
                que.pop();

                if (!node->left && !node->right) return depth;

                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }

            ++depth;
        }

        return depth;
    }
};