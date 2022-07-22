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
    bool solve(TreeNode *root, int k, unordered_set<int> &s)
    {
        if(root == nullptr)
            return false;
        
        int target = k - root->val;
        if(s.find(target) != s.end())
        return true;
        s.insert(root->val);
        if(solve(root->left, k, s) == true)
            return true;
        return solve(root->right, k, s);
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return solve(root, k, s);
    }
};