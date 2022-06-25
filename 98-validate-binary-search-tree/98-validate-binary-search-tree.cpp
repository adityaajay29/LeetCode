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
    TreeNode *prev = nullptr;
    
    bool inorder(TreeNode *root)
    {
        if(root == nullptr)
            return true;
        
        if(inorder(root->left) == false)
            return false;
        
        if(prev != nullptr && prev->val >= root->val) 
            return false;
        
        prev = root;
        // cout<<prev->val<<endl;` 
        
        return inorder(root->right);
    }
    
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
};