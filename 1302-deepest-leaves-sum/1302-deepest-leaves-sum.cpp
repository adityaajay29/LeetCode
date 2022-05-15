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
    int deepestLeavesSum(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        stack<pair<int, int>> s;
        TreeNode *curr=root;
        q.push({root, 1});
        while(curr && !q.empty())
        {
            TreeNode *temp=q.front().first;
            int lvl=q.front().second;
            q.pop();
            s.push({temp->val, lvl});
            if(temp->left)
                q.push({temp->left, lvl+1});
            if(temp->right)
                q.push({temp->right, lvl+1});
            curr=q.front().first;
        }
        int sum=s.top().first;
        int lvl=s.top().second;
        s.pop();
        while(!s.empty() && s.top().second == lvl)
        {
            sum+=s.top().first;
            s.pop();
        }
        return sum;
    }
};