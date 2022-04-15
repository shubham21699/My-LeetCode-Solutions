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
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;
    
    void recover(TreeNode* root) {
        
        if(!root) return;
        recover(root->left);
        
        if(prev) {
            if(root->val < prev->val) {
                if(!first) first = prev;
                second = root;
            }
        }
        
        prev = root;
        recover(root->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
        
        if(!root) return;
        if(!root->left && !root->right) return;
        
        first = NULL; second = NULL; prev = NULL;
        recover(root);
        swap(first->val, second->val);
    }
};