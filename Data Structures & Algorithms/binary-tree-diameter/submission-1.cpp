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
    int diameter_helper(TreeNode* node, int& result) {
        if (node == nullptr) {
            return 0;
        }

        int heightLeft = diameter_helper(node->left, result);
        int heightRight = diameter_helper(node->right, result);

        result = std::max(heightLeft + heightRight, result);

        return 1 + std::max(heightLeft, heightRight);

    }
   
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        diameter_helper(root, result);
        return result;
    }
};
