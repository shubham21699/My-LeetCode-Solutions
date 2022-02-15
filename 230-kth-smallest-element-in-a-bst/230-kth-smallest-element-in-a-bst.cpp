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
    void Inorder(TreeNode* root, vector<int>& in) {
        
        if(!root) return;
        
        Inorder(root->left, in);
        in.push_back(root->val);
        Inorder(root->right, in);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        
        if(!root->left && !root->right && k==1) return root->val;
        
        // DFS:
        stack<TreeNode* > s;
        while(root) {
            s.push(root);
            root = root->left;
        }
        
        while(k) {
            
            TreeNode* current = s.top();
            s.pop();
            k--;
            if(k == 0) return current->val;
            
            // Check for right subtree of current node.
            current = current->right;
            while(current) {
                s.push(current);
                current = current->left;
            }
            
        }
        
        return -1;
        
//         OR: Inorder Traversal
//         vector<int> in;
//         Inorder(root, in);
        
//         return in[k-1];
    }
};