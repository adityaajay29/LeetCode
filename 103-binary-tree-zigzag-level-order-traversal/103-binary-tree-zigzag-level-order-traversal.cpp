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
        
        vector<vector<int>> ans;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        
        while(!q.empty())
        {
            int sz = q.size();
            int lvl = q.front().second;
            vector<int> temp;
            while(sz--)
            {
                TreeNode *curr = q.front().first;
                q.pop();
                if(curr->left)
                    q.push({curr->left, lvl + 1});
                if(curr->right)
                    q.push({curr->right,lvl + 1});
                temp.push_back(curr->val);
            }
            if(lvl % 2)
                reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};