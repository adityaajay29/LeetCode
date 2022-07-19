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
    TreeNode *solve(vector<int> &in, vector<int> &pre, int inStart, int inEnd, int preStart, int preEnd, unordered_map<int, int> &mp)
    {
        if(inStart > inEnd || preStart > preEnd)
            return nullptr;
        
        TreeNode *root = new TreeNode(pre[preStart]);
        
        int part = mp[root->val];
        int newSize = part - inStart;
        
        root->left = solve(in, pre, inStart, part - 1, preStart + 1, preStart + newSize, mp);
        root->right = solve(in, pre, part + 1, inEnd, preStart + newSize + 1, preEnd, mp);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        int n = inorder.size();
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]] = i;
        }
        
        return solve(inorder, preorder, 0, n - 1, 0, n - 1, mp);
    }
};