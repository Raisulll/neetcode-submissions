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

int calculate(TreeNode* root, int& ans) {
    if (!root) return 0;
    int lh = calculate(root->left, ans);
    int rh = calculate(root->right, ans);
    ans = max(ans, lh + rh);
    return 1 + max(lh, rh);
}

class Solution {
   public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        int x = calculate(root, ans);
        return ans;
    }
};
