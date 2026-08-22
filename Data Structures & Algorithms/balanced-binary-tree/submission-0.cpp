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
    int compute_height(TreeNode* node, bool& is_balanced, std::unordered_map<TreeNode*, int>& visited) {

    if (node == nullptr) {
        return 0;
    }

    if (visited.count(node)) {
        return visited[node];
    }

    

    int hleft = compute_height(node->left, is_balanced, visited);
    int hright = compute_height(node->right, is_balanced, visited);

    if (is_balanced) {
        is_balanced = std::abs(hleft - hright) <= 1;
    }

    //std::cout << "height left: " << hleft << std::endl;
    //std::cout << "height right: " << hright << std::endl;

    auto result =  1 + std::max(compute_height(node->left, is_balanced, visited), compute_height(node->right, is_balanced, visited));

    visited.insert({node, result});
    return result;
}

bool isBalanced(TreeNode* node) {

    if (node == nullptr) { return true; }
    std::unordered_map<TreeNode*, int> visited;
    bool is_balanded = true;
    compute_height(node, is_balanded, visited);
    return is_balanded;
}
};
