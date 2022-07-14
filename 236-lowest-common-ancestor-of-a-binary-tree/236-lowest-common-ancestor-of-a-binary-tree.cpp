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
    bool dfs(TreeNode *root, TreeNode *node, vector<TreeNode *> &path)
    {
        if(root == nullptr)
            return false;
        
        if(root == node)
            return true;
        
        path.push_back(root);
        if(dfs(root->left, node, path) || dfs(root->right, node, path))
            return true;
        
        path.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> path1;
        vector<TreeNode *> path2;
        dfs(root, p, path1);
        path1.push_back(p);
        
        dfs(root, q, path2);
        path2.push_back(q);
        
        int n1 = path1.size();
        int n2 = path2.size();
        int i = 0;
        int j = 0;
        TreeNode *lca = nullptr;
        
        while(i < n1 && j < n2)
        {
            if(path1[i] != path2[j])
                break;
            lca = path1[i];
            i++;
            j++;
        }
        return lca;
    }
};