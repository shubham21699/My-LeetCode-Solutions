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
    int sum = 0; 
    
    void Inorder(TreeNode* root) {
        
        if(!root) return;
        
        if(root->left && !root->left->left && !root->left->right) sum += root->left->val;
        if(root->left) Inorder(root->left);
        if(root->right) Inorder(root->right);
        
    }
    
public:
    int sumOfLeftLeaves(TreeNode* root) {
        
        if(!root->left && !root->right) return 0;
        
        sum = 0;
        Inorder(root);
        return sum;
    }
};