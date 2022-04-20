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
//     stack will keep sure that max elements in the stack at a time is the depth of the tree
//     SC : O(h)
    
    stack<TreeNode *>s;
    
    void pushNodes(TreeNode *root)
    {
        while(root)
        {
            s.push(root);
            root=root->left;
        }
    }
    
    BSTIterator(TreeNode* root) {
        pushNodes(root);
    }
    
    int next() {
        TreeNode *node=s.top();
        s.pop();
        pushNodes(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return (!s.empty());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */