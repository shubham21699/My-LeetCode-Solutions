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
#define NO_CAMERA 0
#define HAS_CAMERA 2
#define NOT_NEEDED 1

class Solution {
    
    int cameras = 0;
    
    int dfs(TreeNode* root) {
        
        if(!root) return NOT_NEEDED;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        if(left == NO_CAMERA || right == NO_CAMERA) {
            cameras++;
            return HAS_CAMERA;
        }
        
        if(left == HAS_CAMERA || right == HAS_CAMERA) {
            return NOT_NEEDED;
        }
        
        return NO_CAMERA;
    }
    
public:
    int minCameraCover(TreeNode* root) {
        
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        
        if(dfs(root) == NO_CAMERA) cameras++;
        return cameras;
    }
};