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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        if(!root) return {};
        if(!root->left && !root->right) return {{ root->val }};
        
        vector<vector<int>> result;
        queue<TreeNode* > q;
        q.push(root);
        
        while(!q.empty()) {
            
            int n = q.size();
            vector<int> v;
            
            while(n--) {
                
                TreeNode* current = q.front();
                q.pop();
                v.push_back(current->val);
                
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
                
            }
            
            result.push_back(v);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};