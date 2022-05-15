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
    int deepestLeavesSum(TreeNode* root) {
        
        if(!root) return NULL;
        if(!root->left && !root->right) return root->val;
        
        // Using Level Order Traversal method:
        int result = root->val;
        queue<TreeNode* > q;
        q.push(root);
        
        while(!q.empty()) {
            
            int n = q.size();
            int sum = 0;
            
            while(n--) {
                
                auto current = q.front();
                q.pop();
                
                sum += current->val;
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
                
            }
            
            // At the end it will finally be alloted the value of last level i.e. all last level leaves sum.
            result = sum;
        }
        
        return result;
    }
};