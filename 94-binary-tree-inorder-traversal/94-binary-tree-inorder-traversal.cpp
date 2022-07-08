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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode *curr = root;
        while(curr != nullptr)
        {
//             if left child doesn't exist
            if(curr->left == nullptr)
            {
//                 print the root and goto right
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode *prev = curr->left;
                while(prev->right != nullptr && prev->right != curr)
                {
                    prev = prev->right;
                }
//                 if there was no thread
                if(prev->right == nullptr)
                {
                    prev->right = curr;
                    curr = curr->left;
                }
//                 if thread was present
                else
                {
                    prev->right = nullptr;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};