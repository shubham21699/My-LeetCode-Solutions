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
    int sumTillNow = 0;
    
    void convert(TreeNode* root) {
        
        if(!root) return;
        
        convert(root->right);
        
        sumTillNow += root->val;
        root->val = sumTillNow;
        
        convert(root->left);
        
    }
    
public:
    TreeNode* convertBST(TreeNode* root) {
        
        if(!root) return root;
        if(!root->left && !root->right) return root;
        
        sumTillNow = 0;
        convert(root);
        return root;
    }
};