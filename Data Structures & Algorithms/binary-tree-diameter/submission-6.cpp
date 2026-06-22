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

int height(TreeNode* root) {
    if (!root) return 0;
    int rh = height(root->right);
    int lh = height(root->left);
    // cout<<root->val<<" "<<lh<<" "<<rh<<endl;
    return 1 + max(lh, rh);
}

int calculate(TreeNode* root, int &ans) {
    if (!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    ans = max(ans, lh + rh);
    cout<<"root "<<root->val<<" lh "<<lh<<" rh "<<rh<<" ans "<<ans<<endl;
    calculate(root->left, ans);
    calculate(root->right,ans);
    return ans;
}

class Solution {
   public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        return calculate(root,ans);
    }
};
