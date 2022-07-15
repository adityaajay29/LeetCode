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
    TreeNode *solve(vector<int> &in,vector<int> &post, int inStart, int inEnd, int postStart, int postEnd, unordered_map<int, int> &mp)
    {
        if(inStart > inEnd || postStart < postEnd)
            return nullptr;
        
        TreeNode *root = new TreeNode(post[postStart]);
        int part = mp[root->val];
        int newSize = inEnd - part;
        root->right = solve(in, post, part + 1, inEnd, postStart - 1, postStart - newSize, mp);
        root->left = solve(in, post, inStart, part - 1, postStart - newSize - 1, postEnd, mp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]] = i;
        }
        return solve(inorder, postorder, 0, n - 1, n - 1, 0, mp);
    }
};