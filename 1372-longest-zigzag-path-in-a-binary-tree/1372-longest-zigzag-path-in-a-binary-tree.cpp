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
    int maxLenSoFar = 0;
    
    void check(TreeNode* root, int length, int nextDirection) {
        
        if(!root) return;
        maxLenSoFar = max(maxLenSoFar, length); // Update maxLength so far found.
        
        if(nextDirection == -1) {
            check(root->left, length+1, 1); // Next move to left direction.
            check(root->right, 1, -1); // Or restart from root to right.
        }
        if(nextDirection == 1) {
            check(root->right, length+1, -1); // Next move to right direction.
            check(root->left, 1, 1); // Or restart from root to left.
        }
        
    }
    
public:
    int longestZigZag(TreeNode* root) {
        
        if(!root) return 0;
        if(!root->left && !root->right) return 0;
        
        check(root, 0, -1);
        check(root, 0, 1);
        return maxLenSoFar;
    }
};