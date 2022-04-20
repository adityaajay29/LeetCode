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
class BSTIterator {
public:
    
    vector<TreeNode *>v;
    
    void pushNodes(TreeNode *root)
    {
        if(!root)
            return;
        pushNodes(root->left);
        v.push_back(root);
        pushNodes(root->right);
    }
    
    
    BSTIterator(TreeNode* root) {
        pushNodes(root);
        reverse(v.begin(),v.end());
    }
    
    int next() {
        TreeNode* node=v[v.size()-1];
        v.pop_back();
        return node->val;
    }
    
    bool hasNext() {
        if(v.size()==0)
            return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */