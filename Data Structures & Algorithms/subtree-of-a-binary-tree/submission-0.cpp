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
    bool isSameTree(TreeNode *p, TreeNode *q) {
  if (!p && !q)
    return true;
  if (!p || !q)
    return false;
  if (p->val != q->val)
    return false;
  return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(TreeNode *root, TreeNode *subRoot) {
  if (!root && !subRoot)
    return true;
  if (!root || !subRoot)
    return false;

  std::queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    auto top = q.front();
    q.pop();

    if (top->val == subRoot->val) {
      if (isSameTree(top, subRoot)) {
        return true;
      }
    }

    if (top->left)
      q.push(top->left);
    if (top->right)
      q.push(top->right);
  }

  return false;
}
};
