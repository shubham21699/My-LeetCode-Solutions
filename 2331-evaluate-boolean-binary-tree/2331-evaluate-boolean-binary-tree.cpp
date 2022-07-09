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
    void eval(TreeNode* root) {
        
        if(!root->left && !root->right) return;
        
        if(root->left) eval(root->left);
        if(root->right) eval(root->right);
        root->val = (root->val == 2 ? root->left->val | root->right->val : root->left->val & root->right->val);
    }
    
public:
    bool evaluateTree(TreeNode* root) {
        
        if(!root->left && !root->right) return root->val;
        
        eval(root);
        return root->val;
    }
};