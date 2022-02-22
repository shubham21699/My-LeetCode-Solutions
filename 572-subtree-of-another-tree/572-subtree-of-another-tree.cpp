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
    bool isSame(TreeNode* p, TreeNode* q) {
        
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;
        
        return isSame(p->left, q->left) && isSame(p->right, q->right);
    }
    
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(!root) return false;
        if(root->val == subRoot->val) return isSame(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};