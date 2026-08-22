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
    int dfs(TreeNode* root, int& result) {
        if (root == nullptr) return 0;

        int left = dfs(root->left, result);
        int right = dfs(root->right, result); 
        int leftmax = std::max(left, 0);
        int rightmax = std::max(right, 0);

        result = std::max(result, root->val + leftmax + rightmax);

        return root->val + std::max(leftmax, rightmax);

    }
    int maxPathSum(TreeNode* root) {
    if (root == nullptr) return 0;
        int result = root->val;
        dfs(root, result);
        return result;
    }
};
