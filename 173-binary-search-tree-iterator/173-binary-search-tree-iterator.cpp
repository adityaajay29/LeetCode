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
    vector<int> in;
    
    void solve(TreeNode *root)
    {
        if(root == nullptr)
            return;
        
        solve(root->left);
        in.push_back(root->val);
        solve(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        solve(root);
        reverse(in.begin(), in.end());
    }
    
    int next() {
        int val = in[in.size() - 1];
        in.pop_back();
        return val;
    }
    
    bool hasNext() {
        return !in.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */