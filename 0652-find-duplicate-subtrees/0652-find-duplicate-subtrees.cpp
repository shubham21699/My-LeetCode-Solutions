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
    string dfs(TreeNode* root, unordered_map<string, int>& mp, vector<TreeNode*>& result) {
        
        if(!root) return "";
        
        string s = to_string(root->val) + "," + dfs(root->left, mp, result) + "," +  dfs(root->right, mp, result);
        mp[s]++;
        if(mp[s] == 2) result.push_back(root);
        
        return s;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        unordered_map<string, int> mp;
        vector<TreeNode*> result;
        dfs(root, mp, result);
        
        return result;
    }
};