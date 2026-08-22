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
    int dfs(TreeNode* root, bool& is_balanced) {
        if (!root) {
            return 0;
        }

        int left_height = dfs(root->left, is_balanced);
        int right_height = dfs(root->right, is_balanced);

        if (abs(left_height - right_height) > 1) {
            is_balanced = false;
            return 0;
        }

        return 1 + std::max(left_height, right_height);
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        bool is_balanced = true;
        dfs(root, is_balanced);
        return is_balanced;
    }
};
