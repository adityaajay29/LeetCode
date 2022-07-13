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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int width = 0;
        queue<pair<TreeNode *, long>> q;
        q.push({root, 0});
        while(!q.empty())
        {
            int sz = q.size();
            int minIndex = q.front().second;
            long left, right;
            int tempWidth;
            for(int i=0;i<sz;i++)
            {
                TreeNode *curr = q.front().first;
                long lvl = q.front().second - minIndex;
                q.pop();
                if(curr->left)
                    q.push({curr->left, 2 * lvl + 1});
                if(curr->right)
                    q.push({curr->right, 2 * lvl + 2});
                if(i == 0)
                    left = lvl;
                if(i == sz - 1)
                    right = lvl;
                tempWidth = (right - left) + 1;
            }
            width = max(width, tempWidth);
        }
        return width;
    }
};