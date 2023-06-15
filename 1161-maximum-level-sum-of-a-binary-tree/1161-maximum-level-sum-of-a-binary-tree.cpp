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
    int maxLevelSum(TreeNode* root) {
        
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        
        int maxSumLevel = 1;
        int level = 1;
        int maxSum = INT_MIN;
        queue<TreeNode* > q;
        q.push(root);
        
        while(!q.empty()) {
            
            int sum = 0;
            int n = q.size();
            
            while(n > 0) {
                
                auto curr = q.front();
                sum += curr->val;
                q.pop();
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                
                n--;
            }
            
            if(sum > maxSum) {
                maxSum = sum;
                maxSumLevel = level;
            }
            
            level++;
        }
        
        return maxSumLevel;
    }
};