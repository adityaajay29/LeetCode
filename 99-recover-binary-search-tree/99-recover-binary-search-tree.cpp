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
    void inorder(TreeNode *root,vector<pair<TreeNode *,int> >&v)
    {
        if(!root)
            return;
        inorder(root->left,v);
        v.push_back({root,root->val});
        inorder(root->right,v);
    }
    
    void recoverTree(TreeNode* root) {
        vector<pair<TreeNode *,int> >v;
        inorder(root,v);
        int n=v.size();
        int i;
        int j;
        for(i=1;i<n;i++)
        {
            if(v[i].second<v[i-1].second)
                break;
        }
        int a=v[i-1].second;
        for(j=n-1;j>=1;j--)
        {
            if(v[j-1].second>v[j].second)
                break;
        }
        int b=v[j].second;
        v[i-1].first->val=b;
        v[j].first->val=a;
    }
};