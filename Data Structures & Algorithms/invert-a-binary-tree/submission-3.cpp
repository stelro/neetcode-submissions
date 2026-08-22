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
	void dfs(TreeNode* root) {
		if (!root) return;
		dfs(root->left);
		dfs(root->right);
		std::swap(root->left, root->right);
	}
    TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr) 
		return nullptr;
		dfs(root);
		return root;
    }
};
