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
    bool solve(TreeNode *root, long mini, long maxi)
    {
        if(root == nullptr)
            return true;
        
        int val = root->val;
        if(val <= mini || val >= maxi)
            return false;
        
        if(solve(root->left, mini, val) == false)
            return false;
        
        return solve(root->right, val, maxi);
    }
    
    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MIN, LONG_MAX);
    }
};