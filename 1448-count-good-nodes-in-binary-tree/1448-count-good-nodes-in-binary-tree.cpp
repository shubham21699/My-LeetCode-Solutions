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
    void check(TreeNode* root, int greatestTillNow, int& goodNodes) {
        
        if(!root) return;
        if(root->val >= greatestTillNow) goodNodes++;
        greatestTillNow = max(greatestTillNow, root->val);
        
        check(root->left, greatestTillNow, goodNodes);
        check(root->right, greatestTillNow, goodNodes);
    }
    
public:
    int goodNodes(TreeNode* root) {
        
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        
        int greatestTillNow = root->val;
        int goodNodes = 1;
        
        check(root->left, greatestTillNow, goodNodes);
        check(root->right, greatestTillNow, goodNodes);
        return goodNodes;
    }
};