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
    
    #define noCamera    0
    #define hasCamera   1
    #define notNeeded   2
    
    int dfs(TreeNode *root, int &camera)
    {
        if(root == nullptr)
            return notNeeded;
        
        int left = dfs(root->left, camera);
        int right = dfs(root->right, camera);
        
        if(left == noCamera || right == noCamera)
        {
            camera++;
            return hasCamera;
        }
        
        if(left == hasCamera || right == hasCamera)
            return notNeeded;
        
        return noCamera;
    }
    
    int minCameraCover(TreeNode* root) {
        int camera = 0;
        if(dfs(root, camera) == noCamera)
            camera++;
        
        return camera;
    }
};