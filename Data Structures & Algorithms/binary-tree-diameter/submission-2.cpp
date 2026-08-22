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
    int dfs(TreeNode* node, int& result) {
        if (!node) {
            return 0;
        }

        int left_diameter = dfs(node->left, result);
        int right_dimater = dfs(node->right, result);

        result = std::max(left_diameter + right_dimater, result);
        return 1 + std::max(left_diameter, right_dimater);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }    
        int result = 0;
        dfs(root, result);
        return result;
    }
};
