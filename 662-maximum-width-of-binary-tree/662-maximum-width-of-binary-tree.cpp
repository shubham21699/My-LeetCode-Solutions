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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        
        unsigned long long int maxWidth = 1;
        queue<pair<TreeNode*, unsigned long long int> > q;
        q.push({ root, 1 });
        
        while(!q.empty()) {
            
            unsigned long long int left = q.front().second;
            unsigned long long int right = left;
            int n = q.size();
            
            while(n--) {
                
                TreeNode* current = q.front().first;
                right = q.front().second;
                q.pop();
                
                if(current->left) q.push({ current->left, right*2 });
                if(current->right) q.push({ current->right, right*2 + 1 });
                
            }
            
            maxWidth = max(maxWidth, right - left + 1);
        }
        
        return maxWidth;
    }
};