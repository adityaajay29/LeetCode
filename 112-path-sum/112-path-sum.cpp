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
    bool solve(TreeNode *root, int target)
    {
        if(root == nullptr)
            return false;
        
        if(root ->left == nullptr && root->right == nullptr)
            return target - root->val == 0;
        
        target -= root->val;
        
        if(solve(root->left, target) || solve(root->right, target))
            return true;
        
        target += root->val;
        return false;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
            return false;
        
        return solve(root, targetSum);
    }
};