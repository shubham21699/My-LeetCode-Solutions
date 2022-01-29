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
    unordered_map<int, int> m;
    
    void find(TreeNode* root, int target, int sum, int& result) {
        
        if(!root) return;
        
        // If previous sum and current node value equals to target, then increase count of resultant count.
        if(sum + root->val == target) result++;
        
        // Also add those values which differes by the current sum and root value by target sum.
        result += m[sum + root->val - target];
        
        // Insert sum + root->val in the map
        m[sum + root->val]++;
        
        // Recursively check for left and right subtree
        find(root->left, target, sum + root->val, result);
        find(root->right, target, sum + root->val, result);
        
        // Remove sum + root->val from map if they are not required forward or they will not sum up to
        // th target sum, so discard them.
        m[sum + root->val]--; // Backtracking
    }
    
public:
    int pathSum(TreeNode* root, int targetSum) {
        
        if(!root) return 0;
        if(!root->left && !root->right) {
            if(root->val == targetSum) return 1;
            return 0;
        }
        
        int result = 0;
        
        find(root, targetSum, 0, result);
        return result;
    }
};