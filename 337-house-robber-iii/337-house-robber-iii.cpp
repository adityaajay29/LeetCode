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
    unordered_map<TreeNode *, int> dp;
    int rob(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        if(dp.find(root) != dp.end())
            return dp[root];
        
        int notTake = rob(root->left) + rob(root->right);
        int take = root->val;
        
        if(root->left)
            take += rob(root->left->left) + rob(root->left->right);
        
        if(root->right)
            take += rob(root->right->left) + rob(root->right->right);
        
        return dp[root] = max(take, notTake);
    }
};