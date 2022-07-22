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
    stack<TreeNode *> s;
    
    void solve(TreeNode *root)
    {
        if(root == nullptr)
            return;
        s.push(root);
        solve(root->left);
    }
    
    BSTIterator(TreeNode* root) {
        solve(root);
    }
    
    int next() {
        TreeNode *top = s.top();
        int val = top->val;
        s.pop();
        solve(top->right);
        return val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */