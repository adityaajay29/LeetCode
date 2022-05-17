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
        queue<TreeNode *> q;
        TreeNode *curr=cloned;
        q.push(curr);
        while(!q.empty())
        {
            TreeNode *node=q.front();
            if(node->val == target->val)
                return node;
            q.pop();
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
            curr=q.front();
        }
        return nullptr;
    }
};