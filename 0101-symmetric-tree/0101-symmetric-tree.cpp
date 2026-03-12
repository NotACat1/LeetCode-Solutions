#include <queue>
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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        std::queue<std::pair< TreeNode*, TreeNode*>> que;
        que.push({ root->left, root->right });

        while (!que.empty())
        {
            auto [left, right] = que.front();
            que.pop();

            if (!left && !right) continue;
            if (!left || !right || left->val != right->val) return false;

            que.push({ left->left,  right->right });
            que.push({ left->right, right->left });
        }

        return true;
    }
};