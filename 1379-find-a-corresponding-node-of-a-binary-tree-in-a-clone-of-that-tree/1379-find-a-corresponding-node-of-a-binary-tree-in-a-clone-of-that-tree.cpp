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
    
    void dfs(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        if(!cloned && !original)
            return;
        dfs(original->left, cloned->left, target);
//         follow-up : we have to compare the nodes themselves, not the vals
        if(original == target)
        {
            ans=cloned;
            return;
        }
        dfs(original->right, cloned->right, target);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        dfs(original, cloned, target);
        return ans;
    }
};