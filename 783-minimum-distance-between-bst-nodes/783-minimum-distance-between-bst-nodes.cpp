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
    void Inorder(TreeNode* root, int& minDiff, int& currentRootValue) {
        
        if(!root) return;
        
        if(root->left) Inorder(root->left, minDiff, currentRootValue);
        
        if(currentRootValue >= 0) minDiff = min(minDiff, root->val - currentRootValue);
        currentRootValue = root->val;
        
        if(root->right) Inorder(root->right, minDiff, currentRootValue);
        
    }
    
public:
    int minDiffInBST(TreeNode* root) {
        
        if(!root) return 0;
        if(!root->left && !root->right) return 0;
        
        int minDiff = INT_MAX;
        int currentRootValue = -1;
        Inorder(root, minDiff, currentRootValue);
        return minDiff;
    }
};