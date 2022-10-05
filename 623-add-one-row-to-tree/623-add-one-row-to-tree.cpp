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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root == nullptr)
            return root;
        
        if(depth == 1)
        {
            TreeNode *node = new TreeNode(val);
            node->left = root;
            return node;
        }
        
        queue<pair<TreeNode *, int>> q;
        q.push({root, 1});
        while(!q.empty())
        {
            TreeNode *curr = q.front().first;
            int lvl = q.front().second;
            q.pop();
            if(lvl == depth - 1)
            {
                TreeNode *left = curr->left;
                TreeNode *temp1 = new TreeNode(val);
                curr->left = temp1;
                temp1->left = left;
            
                TreeNode *right = curr->right;
                TreeNode *temp2 = new TreeNode(val);
                curr->right = temp2;
                temp2->right = right;
            }
            else
            {
                if(curr->left)
                    q.push({curr->left, lvl + 1});
                if(curr->right)
                    q.push({curr->right, lvl + 1});
            }
        }
        return root;
    }
};