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
    void flatten(TreeNode* root) {
        
        if(!root || (!root->left && !root->right)) return;
        
        TreeNode* temp = root;
        
        while(temp) {
            
            if(temp->left) {
                if(temp->left->right) {
                    TreeNode* current = temp->left;
                    while(current->right) current = current->right;
                    current->right = temp->right;
                    temp->right = temp->left;
                    temp->left = NULL;
                }
                else {
                    temp->left->right = temp->right;
                    temp->right = temp->left;
                    temp->left = NULL;
                }
            }
            
            temp = temp->right;
        }
        
    }
};