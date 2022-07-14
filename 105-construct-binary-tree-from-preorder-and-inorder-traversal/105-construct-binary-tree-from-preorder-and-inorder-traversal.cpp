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
    TreeNode *solve(vector<int> &pre, vector<int> &in, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int, int> &mp)
    {
        if(preStart > preEnd || inStart > inEnd)
            return nullptr;
        
        TreeNode *root = new TreeNode(pre[preStart]);
        int inRoot = mp[root->val];
        int newIn = inRoot - inStart;
        
        root->left = solve(pre, in, preStart + 1, preStart + newIn, inStart, inRoot - 1, mp);
        root->right = solve(pre, in, preStart + newIn + 1, preEnd, inRoot + 1, inEnd, mp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]] = i;
        }
        return solve(preorder, inorder, 0, n - 1, 0, n - 1, mp);
    }
};