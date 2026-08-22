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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if (!root)
        return nullptr;

    std::queue<TreeNode *> queue;
    queue.push(root);

    while (!queue.empty()) {
        auto top = queue.front();
        queue.pop();

        if (p->val < top->val && q->val < top->val) {
        if (top->left) queue.push(top->left);
        } else if (p->val > top->val && q->val > top->val) {
        if (top->right) queue.push(top->right);
        }  else {
            return top;
        }
    }

    return nullptr;
    }
};
