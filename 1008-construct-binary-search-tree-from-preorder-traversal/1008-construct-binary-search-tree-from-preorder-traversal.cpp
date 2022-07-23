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
    TreeNode* build(vector<int>& preorder, int& index, int n, int boundVal) {
        
        if(index >= n || preorder[index] > boundVal) return NULL;
        
        TreeNode* root = new TreeNode(preorder[index++]);
        
        root->left = build(preorder, index, n, root->val);
        root->right = build(preorder, index, n, boundVal);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int n = preorder.size();
        if(n == 0) return NULL;
        if(n == 1) return new TreeNode(preorder[0]);
        
        TreeNode* root = new TreeNode(preorder[0]);
        int index = 0;
        return build(preorder, index, n, INT_MAX);
    }
};