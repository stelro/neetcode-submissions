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
    TreeNode *build(const std::vector<int> &preorder,
                std::unordered_map<int, int> &inorder, int &preorder_idx,
                int left, int right) {
  if (left > right)
    return nullptr;
  int root_val = preorder[preorder_idx++];
  TreeNode* root = new TreeNode(root_val);
  int mid = inorder[root_val];
  root->left = build(preorder, inorder, preorder_idx, left, mid - 1);
  root->right = build(preorder, inorder, preorder_idx, mid + 1, right);
  return root;
}

TreeNode *buildTree(const std::vector<int> &preorder,
                    const std::vector<int> &inorder) {

  std::unordered_map<int, int> in;
  for (int i = 0; i < inorder.size(); i++) {
    in[inorder[i]] = i;
  }
  int preorder_idx = 0;
  return build(preorder, in, preorder_idx, 0, inorder.size() - 1);
}
};
