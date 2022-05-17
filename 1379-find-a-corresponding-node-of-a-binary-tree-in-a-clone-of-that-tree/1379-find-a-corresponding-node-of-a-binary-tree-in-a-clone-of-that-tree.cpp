/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!cloned)
            return nullptr;
        TreeNode *left=getTargetCopy(original->left, cloned->left, target);
        if(left)
            return left;
        if(original == target)
            return cloned;
        TreeNode *right=getTargetCopy(original->right, cloned->right, target);
        return right;
    }
};