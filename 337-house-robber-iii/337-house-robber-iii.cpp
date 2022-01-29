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
    unordered_map<TreeNode*, int> m;
    
    int maxAmount(TreeNode* root) {
        
        if(!root) return 0;
        if(m[root]) return m[root];
        
        int amountIncluding = root->val, amountNotIncluding = 0;
        
        if(root->left) amountIncluding += maxAmount(root->left->left) + maxAmount(root->left->right);
        if(root->right) amountIncluding += maxAmount(root->right->left) + maxAmount(root->right->right);
        amountNotIncluding = maxAmount(root->left) + maxAmount(root->right);
        
        return m[root] = max(amountIncluding, amountNotIncluding);
    }
    
public:
    int rob(TreeNode* root) {
        
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;
        
        // DFS Approach with Memoization
        return maxAmount(root);
    }
};