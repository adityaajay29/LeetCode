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
struct node
{
    int sum;
    int mini;
    int maxi;
    node(int a, int b, int c)
    {
        sum = a;
        mini = b;
        maxi = c;
    }
};

node solve(TreeNode *root, int &c)
{
    if(root == nullptr)
        return node(0, INT_MAX, INT_MIN);
    
    node left = solve(root->left, c);
    node right = solve(root->right, c);
    if(root->val > left.maxi && root->val < right.mini)
    {
        c = max(c, left.sum + right.sum + root->val);
        return node(root->val + left.sum + right.sum, min(root->val, left.mini), max(root->val, right.maxi));
    }
    return node(max(left.sum, right.sum), INT_MIN, INT_MAX);
}

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int c = 0;
        solve(root, c);
        return (c < 0 ? 0 : c);
    }
};