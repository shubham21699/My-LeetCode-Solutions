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
    
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int start, int end, int& index) {
        
        if(start > end) return NULL;
        
        TreeNode* root = new TreeNode(postorder[index++]);
        int rootIndex = m[root->val];
        
        root->right = build(inorder, postorder, rootIndex+1, end, index);
        root->left = build(inorder, postorder, start, rootIndex-1, index);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = inorder.size();
        if(n == 1) {
            TreeNode* result = new TreeNode(inorder[0]);
            return result;
        }
        
        for(int i=0 ; i<n ; i++) {
            m[inorder[i]] = i;
        }
        
        reverse(postorder.begin(), postorder.end());
        int index = 0;
        return build(inorder, postorder, 0, n-1, index);
        
    }
};