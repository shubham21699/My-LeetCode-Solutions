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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> result;
        if(!root) return result;
        if(!root->left && !root->right) {
            result.push_back(root->val / 1.0);
            return result;
        }
        
        queue<TreeNode* > q;
        q.push(root);
        
        while(!q.empty()) {
            
            int n = q.size();
            int k = n;
            double sum = 0;
            
            while(k--) {
                
                TreeNode* current = q.front();
                q.pop();
                sum += current->val;
                
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
                
            }
            
            double ans = sum/n;
            result.push_back(ans);
        }
        
        return result;
    }
};