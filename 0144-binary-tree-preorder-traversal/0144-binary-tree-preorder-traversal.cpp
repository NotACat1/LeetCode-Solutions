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
    std::vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};

        std::vector<int> result;
        auto current = root;

        while (current) {
            if (!current->left) {
                result.push_back(current->val);
                current = current->right;
            }
            else {
                auto predecessor = current->left;
                while (predecessor->right && predecessor->right != current) {
                    predecessor = predecessor->right;
                }

                if (!predecessor->right) {
                    result.push_back(current->val);
                    predecessor->right = current;
                    current = current->left;
                }
                else {
                    predecessor->right = nullptr;
                    current = current->right;
                }
            }
        }

        return result;
    }
};