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
    
    #define pleaseCover 0
    #define hasCamera   1
    #define isCovered   2
    
    int dfs(TreeNode *root, int &camera)
    {
        if(root == nullptr)
            return isCovered;
        
        int left = dfs(root->left, camera);
        int right = dfs(root->right, camera);
        
        if(left == pleaseCover || right == pleaseCover)
        {
            camera++;
            return hasCamera;
        }
        
        if(left == hasCamera || right == hasCamera)
            return isCovered;
        
        return pleaseCover;
    }
    
    int minCameraCover(TreeNode* root) {
        int camera = 0;
        if(dfs(root, camera) == pleaseCover)
            camera++;
        
        return camera;
    }
};