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
    void rootToLeaf(TreeNode* root, int num, long long& sum) {
        
        if(!root) return;
        if(!root->left && !root->right) {
            num = num*10 + root->val;
            sum += num;
            return;
        }
        
        rootToLeaf(root->left, num*10 + root->val, sum);
        rootToLeaf(root->right, num*10 + root->val, sum);
    }
    
    int sumNumbers(TreeNode* root) {
        
        long long sum = 0;
        int num = 0;
        
        rootToLeaf(root, num, sum);
        return sum;
    }
};