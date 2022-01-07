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
    
    TreeNode* build(vector<int>& preorder, vector<int>& postorder, int start, int end, int& index, int size) {
        
        if(start > end || index >= size) return NULL;
        
        TreeNode* root = new TreeNode(preorder[index++]);
        if(start == end) return root;
        
        int rootIndex = m[preorder[index]];
        
        if(rootIndex <= end) {
            root->left = build(preorder, postorder, start, rootIndex, index, size);
            root->right = build(preorder, postorder, rootIndex+1, end-1, index, size);   
        }
        
        return root;
    }
    
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        int n = preorder.size();
        if(n == 1) {
            TreeNode* result = new TreeNode(preorder[0]);
            return result;
        }
        
        for(int i=0 ; i<n ; i++) {
            m[postorder[i]] = i;
        }
        
        int index = 0;
        return build(preorder, postorder, 0, n-1, index, n);
    }
};