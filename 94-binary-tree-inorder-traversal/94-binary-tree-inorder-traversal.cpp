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
    void Inorder(TreeNode* root, vector<int>& inorder) {
        
        if(!root) return;
        
        Inorder(root->left, inorder);
        inorder.push_back(root->val);
        Inorder(root->right, inorder);
        
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> inorder;
        if(!root) return inorder;
        
        Inorder(root, inorder);
        return inorder;
        
    }
};