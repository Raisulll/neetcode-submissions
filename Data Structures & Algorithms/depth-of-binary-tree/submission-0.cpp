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
int traverse(TreeNode* root, int cnt, int ans){
    if(root==nullptr) return cnt-1;
    int x=traverse(root->right, cnt+1, ans);
    int y=traverse(root->left, cnt+1, ans);
    ans=max(x,y);
    return ans;
}
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return traverse(root, 1, 1);
    }
};
