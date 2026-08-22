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
TreeNode* build(const std::vector<int>& preorder,
     std::unordered_map<int, int>& inorder,
    int& pre_index,int left, int right) {

    if (left > right) return nullptr;
    TreeNode* root = new TreeNode(preorder[pre_index]);
    int mid = inorder[preorder[pre_index]];
    pre_index++;
    root->left = build(preorder, inorder, pre_index, left, mid - 1);
    root->right = build(preorder, inorder, pre_index, mid + 1, right);
    return root;
}

TreeNode *buildTree(const std::vector<int> &preorder,
                    const std::vector<int> &inorder) {
    if (preorder.empty() || inorder.empty()) return nullptr;

    std::unordered_map<int, int> in;
    for (int i = 0; i < inorder.size(); i++) {
        in[inorder[i]] = i;
    }

    int pre_index = 0;

    return build(preorder, in, pre_index, 0, inorder.size() - 1);
}
};
