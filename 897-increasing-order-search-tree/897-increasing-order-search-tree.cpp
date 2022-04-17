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
    queue<TreeNode *>q;
    void inorder(TreeNode *root)
    {
        if(!root)
            return;
        inorder(root->left);
        q.push(new TreeNode(root->val));
        inorder(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        TreeNode *dummy = new TreeNode(0);
        TreeNode *curr=dummy;
        while(!q.empty())
        {
            curr->right=q.front();
            curr->left=NULL;
            curr=curr->right;
            q.pop();
        }
        return dummy->right;
    }
};