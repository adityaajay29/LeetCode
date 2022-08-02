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
        
        queue<pair<TreeNode *, long>> q;
        q.push({root, 0});
        int ans = 0;
        while(!q.empty())
        {
            int sz = q.size();
            int minLvl = q.front().second;
            int left = 0, right = 0;
            for(int i=0;i<sz;i++)
            {
                TreeNode *curr = q.front().first;
                int lvl = q.front().second;
                q.pop();
                int currLvl = lvl - minLvl;
                if(curr->left)
                    q.push({curr->left, (long)2 * currLvl + 1});
                if(curr->right)
                    q.push({curr->right, (long)2 * currLvl + 2});
                if(i == 0)
                    left = currLvl;
                if(i == sz - 1)
                    right = currLvl;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};