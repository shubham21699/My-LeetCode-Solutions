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
    void prune(TreeNode* root, TreeNode* copy) {
        
        if(!root) return;
        
        prune(root->left, copy->left);
        if(copy->left && copy->left->val == 0) root->left = NULL;
        
        prune(root->right, copy->right);
        if(copy->right && copy->right->val == 0) root->right = NULL;
    }
    
    void create(TreeNode* &copy, TreeNode* root) {
        
        if(!root) return;
        
        if(root->left) copy->left = new TreeNode(root->left->val);
        if(root->right) copy->right = new TreeNode(root->right->val);
        
        create(copy->left, root->left);
        create(copy->right, root->right);
        
        copy->val += (copy->left ? copy->left->val : 0) + (copy->right ? copy->right->val : 0);
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        
        if(!root) return NULL;
        
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        
        if(!root->left && !root->right && root->val == 0) return NULL;
        
        return root;
        
//         // OR:
//         TreeNode* copy = new TreeNode(root->val);
//         create(copy, root);
        
//         // If root->val of copy tree is 0, means all subtree doesn't have 1 in them
//         if(copy->val == 0) return NULL;
        
//         if(copy->left && copy->left->val == 0) root->left = NULL;
//         if(copy->right && copy->right->val == 0) root->right = NULL;
        
//         if(!root->left && !root->right) return root;
        
//         prune(root, copy);
//         return root;
    }
};