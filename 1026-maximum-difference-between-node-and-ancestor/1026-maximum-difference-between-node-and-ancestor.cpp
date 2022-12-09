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
    int maxDiff(TreeNode* root, int minVal, int maxVal) {
        
        if(!root) return abs(maxVal - minVal);
        
        // Updating max and min values
        minVal = min(root->val, minVal);
        maxVal = max(root->val, maxVal);
        
        // Traverse
        int left = maxDiff(root->left, minVal, maxVal);
        int right = maxDiff(root->right, minVal, maxVal);
        
        return max(left, right);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        
        if(!root) return 0;
        
        return maxDiff(root, root->val, root->val);
    }
};