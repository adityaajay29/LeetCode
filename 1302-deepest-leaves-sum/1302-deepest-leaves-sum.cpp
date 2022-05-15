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
    
    int sum = 0;
    
    int dfs(TreeNode* root,int &depth, int lvl = 0) 
    {
        if(!root) 
            return 0;
        if(!root -> left && !root -> right)
        {
            if(lvl == depth) 
                sum += root -> val;
            else if(lvl > depth)
            {
                sum = root -> val;
                depth = lvl; 
            }
        }
        dfs(root -> left, depth, lvl + 1); 
        dfs(root -> right, depth, lvl + 1);
        return sum;
    }

    int deepestLeavesSum(TreeNode* root) {
        int depth=0;
        return dfs(root, depth, 0);
    }
};