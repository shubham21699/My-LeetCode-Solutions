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
    void traverse(TreeNode* root, unordered_map<int, int>& freq, int& maxFreq) {
        
        if(!root) return;
        
        freq[root->val]++;
        maxFreq = max(maxFreq, freq[root->val]);
        
        traverse(root->left, freq, maxFreq);
        traverse(root->right, freq, maxFreq);
    }
    
    vector<int> findMode(TreeNode* root) {
        
        if(!root) return {};
        if(!root->left && !root->right) return { root->val };
        
        unordered_map<int, int> freq;
        int maxFreq = 0;
        
        traverse(root, freq, maxFreq);
        
        vector<int> result;
        
        for(auto it : freq) {
            if(it.second == maxFreq) result.push_back(it.first);
        }
        
        return result;
    }
};