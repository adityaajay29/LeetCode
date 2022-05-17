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
    TreeNode *ans=NULL;
    
    void dfs(TreeNode *cloned, TreeNode *target)
    {
        if(!cloned)
            return;
        dfs(cloned->left, target);
        if(cloned->val == target->val)
        {
            ans=cloned;
            return;
        }
        dfs(cloned->right, target);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        dfs(cloned, target);
        return ans;
    }
};