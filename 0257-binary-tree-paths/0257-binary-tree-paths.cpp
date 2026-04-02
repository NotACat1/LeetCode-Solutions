#include <vector>
#include <string>

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
private:
    void dfs(TreeNode* node, std::string path, std::vector<std::string>& result) {
        if (!node) return;

        path += std::to_string(node->val);

        if (!node->left && !node->right) {
            result.push_back(path);
            return;
        }

        path += "->";
        dfs(node->left,  path, result);
        dfs(node->right, path, result);
    }

public:
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> result;
        if (!root) return result;

        dfs(root, "", result);
        return result;
    }
};