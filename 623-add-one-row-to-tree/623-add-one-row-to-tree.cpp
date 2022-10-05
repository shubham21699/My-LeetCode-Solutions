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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(!root) {
            TreeNode* newRoot = new TreeNode(val);
            return newRoot;
        }
        
        if(depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        queue<TreeNode* > q;
        q.push(root);
        
        while(depth > 2) {
            
            int n = q.size();
            
            while(n--) {
                
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                
            }
            
            depth--;
        }
        
        while(!q.empty()) {
            
            TreeNode* curr = q.front();
            q.pop();
            TreeNode* newRowNode1 = new TreeNode(val);
            TreeNode* newRowNode2 = new TreeNode(val);
            
            if(curr->left) newRowNode1->left = curr->left;
            if(curr->right) newRowNode2->right = curr->right;
            
            curr->left = newRowNode1;
            curr->right = newRowNode2;
        }
        
        return root;
    }
};