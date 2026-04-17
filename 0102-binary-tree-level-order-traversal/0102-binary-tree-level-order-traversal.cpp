#include <vector>
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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;

        if (root == nullptr) return result;

        std::queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            std::vector<int> level;
            auto size = que.size();

            for (size_t i = 0; i < size; i++) {
                auto node = que.front();
                que.pop();

                level.push_back(node->val);

                if (node->left != nullptr) que.push(node->left);
                if (node->right != nullptr) que.push(node->right);
            }            

            result.push_back(level);
        }

        return result;
    }
};