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
    unordered_map<int, int> m;
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int start, int end, int& index) {
        
        if(start > end) return NULL;
        
        TreeNode* root = new TreeNode(preorder[index++]);
        
        int rootInd = m[root->val];
        
        root->left = build(preorder, inorder, start, rootInd-1, index);
        root->right = build(preorder, inorder, rootInd+1, end, index);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = preorder.size();
        
        if(n == 1) {
            TreeNode* result = new TreeNode(preorder[0]);
            return result;
        }
        
        for(int i=0 ; i<n ; i++) {
            m[inorder[i]] = i;
        }
        
        int index = 0;
        return build(preorder, inorder, 0, n-1, index);
    }
};