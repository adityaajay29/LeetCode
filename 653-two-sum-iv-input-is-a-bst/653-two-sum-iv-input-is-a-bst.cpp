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
    void solve(TreeNode*root, vector<int> &in)
    {
        if(root == nullptr)
            return;
        solve(root->left, in);
        in.push_back(root->val);
        solve(root->right, in);
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> in;
        solve(root, in);
        int l = 0;
        int h = in.size() - 1;
        while(l < h)
        {
            int sum = in[l] + in[h];
            if(sum == k)
                return true;
            
            if(sum > k)
                h--;
            else
                l++;
        }
        return false;
    }
};