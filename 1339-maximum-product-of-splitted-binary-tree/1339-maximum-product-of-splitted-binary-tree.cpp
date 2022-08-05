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
    int mod = pow(10, 9) + 7;
    void checkProd(TreeNode* root, long long& ans, int totalSum) {
        
        if(!root) return;
        if(!root->left && !root->right) return;
        
        int leftSubtreeSum = root->left ? root->left->val : 0;
        int rightSubtreeSum = root->right ? root->right->val : 0;
        
        // (totalSum - subtreeSum) will give the sum of the rest of the tree sum excluding particular subtree sum.
        ans = max({ ans, (long long) (totalSum - leftSubtreeSum) * leftSubtreeSum, (long long) (totalSum - rightSubtreeSum) * rightSubtreeSum });
        
        checkProd(root->left, ans, totalSum);
        checkProd(root->right, ans, totalSum);
    }
    
    void subTreeSum(TreeNode* root) {
        
        if(!root) return;
        if(!root->left && !root->right) return;
        
        subTreeSum(root->left);
        subTreeSum(root->right);
        root->val += (root->left ? root->left->val : 0) + (root->right ? root->right->val : 0);
    }
    
    int maxProduct(TreeNode* root) {
        
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;
        
        subTreeSum(root);
        int totalSum = root->val;
        long long ans = 0;
        
        checkProd(root, ans, totalSum);
        return ans % mod;
    }
};