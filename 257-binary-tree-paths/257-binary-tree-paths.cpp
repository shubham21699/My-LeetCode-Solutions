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
    void paths(TreeNode* root, string path, vector<string>& result) {
        
        if(!root->left && !root->right) {
            result.push_back(path);
            return;
        }
        
        if(root->left) paths(root->left, path + "->" + to_string(root->left->val), result);
        if(root->right) paths(root->right, path + "->" + to_string(root->right->val), result);
        
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> result;
        if(!root) return result;
        
        string path = to_string(root->val);
        
        paths(root, path, result);
        return result;
    }
};