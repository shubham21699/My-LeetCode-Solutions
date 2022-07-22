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
    void Preorder(TreeNode* root, vector<int>& pre) {
        
        if(!root) return;
        
        pre.push_back(root->val);
        Preorder(root->left, pre);
        Preorder(root->right, pre);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        
        if(!root) return {};
        if(!root->left && !root->right) return { root->val };
        
        vector<int> preorder;
        Preorder(root, preorder);
        return preorder;
    }
};