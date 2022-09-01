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
    void solve(TreeNode *root, int &ans, int maxi)
    {
        if(root == nullptr)
            return;
        
        if(root->val >= maxi)
        {
            ans++;
            maxi = root->val;
        }
        solve(root->left, ans, maxi);
        solve(root->right, ans, maxi);
    }
    
    int goodNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int ans = 1;
        int val = root->val;
        solve(root->left, ans, val);
        solve(root->right, ans, val);
        return ans;
    }
};