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
    void getPath(TreeNode* root, int sum, int target, vector<vector<int>>& result, vector<int> v) {
        
        if(!root) return;
        v.push_back(root->val);
        
        if(sum + root->val == target && !root->left && !root->right) {
            result.push_back(v);
            return;
        }
        
        if(root->left) getPath(root->left, sum + root->val, target, result, v);
        if(root->right) getPath(root->right, sum + root->val, target, result, v);
        v.pop_back();
        
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
         
        if(!root) return {};
        if(!root->left && !root->right) {
            if(targetSum == root->val) return {{ root->val }};
            return {};
        }
        
        vector<vector<int>> result;
        vector<int> v;
        
        getPath(root, 0, targetSum, result, v);
        return result;
    }
};