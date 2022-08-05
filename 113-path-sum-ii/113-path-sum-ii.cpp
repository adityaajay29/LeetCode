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
    void solve(TreeNode *root, int target, vector<vector<int>> &ans, vector<int> temp)
    {
        if(root == nullptr)
            return;
        
        if(root->left == nullptr && root->right == nullptr)
        {
            if(target - root->val == 0)
            {
                temp.push_back(root->val);
                ans.push_back(temp);
                return;
            }
        }
        target -= root->val;
        temp.push_back(root->val);
        solve(root->left, target, ans, temp);
        solve(root->right, target, ans, temp);
        temp.pop_back();
        target += root->val;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
            return {};
        
        vector<vector<int>> ans;
        solve(root, targetSum, ans, {});
        return ans;
    }
};