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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
//         if we reach null, return NULL
        if(!root)
            return NULL;
//         if the curr val lies in the required range or is low/high
//         then make the left and right connections from left and right subtreees respectively
        if(root->val>=low && root->val<=high)
        {
//             making left connection
            root->left=trimBST(root->left,low,high);
//             making right connection
            root->right=trimBST(root->right,low,high);
        }
//         if below range, goto right 
        if(root->val<low)
            return trimBST(root->right,low,high);
//         else, go to left
        else if(root->val>high)
            return trimBST(root->left,low,high);
//             return the root after all connections
            return root;
    }
};