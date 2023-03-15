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
    bool isCompleteTree(TreeNode* root) {
        
        if(!root) return true;
        if(!root->left && !root->right) return true;
        
        vector<int> order;
        order.push_back(root->val);
        queue<TreeNode* > q;
        q.push(root);
        
        while(!q.empty()) {
            
            int n = q.size();
            
            while(n--) {
                
                TreeNode* current = q.front();
                q.pop();
                
                if(current->left) {
                    order.push_back(current->left->val);
                    q.push(current->left);
                }
                else order.push_back(-1);
                
                if(current->right) {
                    order.push_back(current->right->val);
                    q.push(current->right);
                }
                else order.push_back(-1);
                
            }
            
        }
        
        int n = order.size();
        int i = 0;
        
        while(i < n && order[i] != -1) i++;
        
        while(i < n) {
            if(order[i] != -1) return false;
            i++;
        }
        
        return true;
    }
};