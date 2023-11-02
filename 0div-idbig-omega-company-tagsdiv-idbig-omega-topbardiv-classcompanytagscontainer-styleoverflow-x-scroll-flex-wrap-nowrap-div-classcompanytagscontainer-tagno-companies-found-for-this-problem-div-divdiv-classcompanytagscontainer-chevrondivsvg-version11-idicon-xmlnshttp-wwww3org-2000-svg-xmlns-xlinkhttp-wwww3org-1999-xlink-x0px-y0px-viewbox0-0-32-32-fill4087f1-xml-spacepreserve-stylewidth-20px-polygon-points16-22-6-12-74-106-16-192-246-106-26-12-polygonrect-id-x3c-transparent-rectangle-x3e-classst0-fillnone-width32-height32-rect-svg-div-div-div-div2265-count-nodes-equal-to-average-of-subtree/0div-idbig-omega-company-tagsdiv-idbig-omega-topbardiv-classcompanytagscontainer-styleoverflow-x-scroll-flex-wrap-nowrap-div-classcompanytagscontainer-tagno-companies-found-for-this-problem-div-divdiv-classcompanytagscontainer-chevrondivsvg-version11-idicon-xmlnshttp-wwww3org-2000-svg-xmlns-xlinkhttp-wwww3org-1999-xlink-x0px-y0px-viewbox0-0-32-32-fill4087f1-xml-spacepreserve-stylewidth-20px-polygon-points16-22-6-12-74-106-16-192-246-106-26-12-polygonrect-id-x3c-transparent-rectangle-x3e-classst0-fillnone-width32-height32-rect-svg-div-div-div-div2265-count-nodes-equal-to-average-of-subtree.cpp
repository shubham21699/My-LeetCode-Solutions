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
    int traverse(TreeNode* root, int& count) {

        if(!root) return 0;
        
        int nodes = 1 + traverse(root->left, count) + traverse(root->right, count);
        
        int subtreeSum = 0;
        if(root->left) subtreeSum += root->left->val;
        if(root->right) subtreeSum += root->right->val;
        
        if(((subtreeSum + root->val) / nodes) == root->val) count++;
        root->val += subtreeSum;
        
        return nodes;
    }
    
    int averageOfSubtree(TreeNode* root) {
        
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        
        int count = 0;
        traverse(root, count);
        return count;
    }
};