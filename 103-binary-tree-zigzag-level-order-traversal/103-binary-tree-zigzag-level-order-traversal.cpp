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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};
        
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        vector<vector<int>> ans;
        
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> temp(sz);
            for(int i=0;i<sz;i++)
            {
                TreeNode *curr = q.front().first;
                int lvl = q.front().second;
                q.pop();
                if(curr->left)
                    q.push({curr->left, lvl + 1});
                if(curr->right)
                    q.push({curr->right, lvl + 1});
                int index = (lvl % 2 == 0) ? i : sz - 1 - i;
                temp[index] = curr->val;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};