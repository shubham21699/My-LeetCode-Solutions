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
    int max_sum = INT_MIN;
    
    int calc(TreeNode* root) {
        
        if(!root) return 0;
        
        int left_sum = max(calc(root->left), 0);
        int right_sum = max(calc(root->right), 0);
        
        int sum = root->val + left_sum + right_sum;
        max_sum = max(max_sum, sum);
        
        // Maximum path for parent call of root. 
        // This path must include at-most 1 child of root
        return max(max(left_sum, right_sum) + root->val, root->val);
    }
    
public:
    int maxPathSum(TreeNode* root) {
        
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;
        
        calc(root);
        return max_sum;
    }
};