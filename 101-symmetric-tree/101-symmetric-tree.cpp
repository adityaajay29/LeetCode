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
    TreeNode *mirrorTree(TreeNode *root)
    {
        if(root == nullptr)
            return nullptr;
        TreeNode *newRoot = new TreeNode(root->val);
        newRoot->left = mirrorTree(root->right);
        newRoot->right = mirrorTree(root->left);
        return newRoot;
    }
    
    bool isSame(TreeNode *p, TreeNode *q)
    {
        if(p == nullptr || q == nullptr)
            return p == q;
        
        if(p->val != q->val)
            return false;
        
        if(isSame(p->left, q->left) == false)
            return false;
        
        return isSame(p->right, q->right);
    }
    
    bool isSymmetric(TreeNode* root) {
        TreeNode *mirror = mirrorTree(root);
        return isSame(root, mirror);
    }
};