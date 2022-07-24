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
    bool check(TreeNode* root, int k, unordered_map<int, int>& mp) {
        
        if(!root) return false;
        if(mp.find(k-root->val) != mp.end()) return true;
        else mp[root->val]++;
        
        return check(root->left, k, mp) || check(root->right, k, mp);
    }
    
    bool findTarget(TreeNode* root, int k) {
        
        if(!root || (!root->left && !root->right)) return false;
        unordered_map<int, int> mp;
        
        return check(root, k, mp);
    }
};