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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode *curr = root;
        while(curr != nullptr)
        {
//             if no left
            if(curr->left == nullptr)
            {
                preorder.push_back(curr->val);
                curr = curr->right;
            }
//             if left, goto left, goto its rightmost node
            else
            {
                TreeNode *prev = curr->left;
                while(prev->right != nullptr && prev->right != curr)
                {
                    prev = prev->right;
                }
//                 if there was no thread, then print the root and connect thread
                if(prev->right == nullptr)
                {
                    preorder.push_back(curr->val);
                    prev->right = curr;
                    curr = curr->left;
                }
//                 break the thread
                else
                {
                    prev->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }
};