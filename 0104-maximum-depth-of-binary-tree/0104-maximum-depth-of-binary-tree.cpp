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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        std::queue<TreeNode*> que;
        que.push(root);
        int depth = 0;

        while (!que.empty())
        {
            int levelSize = que.size();

            for (int i = 0; i < levelSize; ++i)
            {
                auto node = que.front();
                que.pop();

                if (node->left)  que.push(node->left);
                if (node->right) que.push(node->right);
            }

            ++depth;
        }

        return depth;
    }
};