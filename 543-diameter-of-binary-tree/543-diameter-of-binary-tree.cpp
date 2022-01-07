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
    int height(TreeNode* root) {
        
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        if(!root->left) return 1 + height(root->right);
        if(!root->right) return 1 + height(root->left);
        
        return 1 + max(height(root->left), height(root->right));
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(!root) return 0;
        if(!root->left && !root->right) return 0;
        
        int ans = height(root->left) + height(root->right);
        
        return max({ ans, diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right) });
        
    }
};