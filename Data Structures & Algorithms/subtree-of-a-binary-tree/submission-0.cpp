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

bool sameTree(TreeNode* root, TreeNode* subRoot) {
    if (!root and !subRoot) return true;
    if (!root or !subRoot) return false;
    if (root->val != subRoot->val) return false;
    return sameTree(root->right, subRoot->right) & sameTree(root->left, subRoot->left);
}

class Solution {
   public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root and !subRoot) return true;
        if (!root or !subRoot) return false;
        if (sameTree(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) | isSubtree(root->right, subRoot);
    }
};
