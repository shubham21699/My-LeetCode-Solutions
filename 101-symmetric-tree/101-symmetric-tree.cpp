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
    bool isSymmetric(TreeNode* root) {
        
        if(!root) return true;
        if(!root->left && !root->right) return true;
        if(!root->left || !root->right) return false;
        if(root->left->val != root->right->val) return false;

        // BFS Solution:        
        queue<TreeNode* > q;
        q.push(root);
        
        while(!q.empty()) {
            
            int n = q.size();
            vector<int> v;
            
            while(n--) {
                
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr->left) {
                    q.push(curr->left);
                    v.push_back(curr->left->val);
                }
                else v.push_back(0);
                
                if(curr->right) {
                    q.push(curr->right);
                    v.push_back(curr->right->val);
                }
                else v.push_back(0);
                
            }
            
            int i = 0;
            int j = v.size()-1;
            
            while(i < j) {
                if(v[i] != v[j]) return false;
                i++;
                j--;
            }
            
        }
        
        return true;
    }
};