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

		int left_height = dfs(root->left, result);
		int right_height = dfs(root->right, result);

		result = std::max(result, left_height + right_height);


		return 1 + std::max(left_height, right_height);

	}
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
		return 0;

	int result = 0;

	dfs(root, result);

	return result;
    }
};
