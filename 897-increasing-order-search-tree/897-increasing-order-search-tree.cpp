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
    TreeNode* toInorder(TreeNode* root, TreeNode* prev) {
        
        if(!root) return prev;
        
        TreeNode* result = toInorder(root->left, root);
        
        root->left = NULL;
        root->right = toInorder(root->right, prev);
        
        return result;
    }
    
public:
    TreeNode* increasingBST(TreeNode* root) {
        
        if(!root) return NULL;
        if(!root->left && !root->right) return root;
        
        TreeNode* prev = NULL;
        root = toInorder(root, prev);
        return root;
    }
};