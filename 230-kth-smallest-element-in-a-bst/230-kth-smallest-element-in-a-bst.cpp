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
    void solve(TreeNode *root, int &i, int k, int &ans)
    {
        if(root == nullptr)
            return;
        
        solve(root->left, i, k, ans);
        i++;
        if(k == i)
        {
            ans = root->val;
            return;
        }
        solve(root->right, i, k, ans);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        int ans = 0;
        solve(root, i, k, ans);
        return ans;
    }
};