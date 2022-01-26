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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int> > result;
        if(!root) return result;
        if(!root->left && !root->right) {
            result.push_back({ root->val });
            return result;
        }
        
        queue<TreeNode* > q;
        q.push(root);
        
        while(!q.empty()) {
            
            int size = q.size();
            vector<int> v;
            
            while(size--) {
                
                TreeNode* current = q.front();
                q.pop();
                v.push_back(current->val);
                
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
                
            }
            
            result.push_back(v);
        }
        
        return result;
    }
};