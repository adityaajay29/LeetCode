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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == nullptr)
            return {};
        
//         triplet : node, hor, ver
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        
        map<int, map<int, multiset<int>>> mp;
        
        while(!q.empty())
        {
            TreeNode *curr = q.front().first;
            int hor = q.front().second.first;
            int ver = q.front().second.second;
            q.pop();
            mp[ver][hor].insert(curr->val);
            if(curr->left)
                q.push({curr->left, {hor + 1, ver - 1}});
            if(curr->right)
                q.push({curr->right, {hor + 1, ver + 1}});
        }
        vector<vector<int>> ans;
        for(pair<int, map<int, multiset<int>>> x : mp)
        {
            int ver = x.first;
            map<int, multiset<int>> hor = x.second;
            vector<int> temp;
            for(pair<int, multiset<int>> lvl : hor)
            {
                multiset<int> set = lvl.second;
                for(int node : set)
                {
                    temp.push_back(node);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};