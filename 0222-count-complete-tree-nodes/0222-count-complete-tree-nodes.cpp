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
    int countNodes(TreeNode* root) {
        
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        
        TreeNode* leftRoot = root;
        TreeNode* rightRoot = root;
        int leftHt = 0;
        int rightHt = 0;
        
        while(leftRoot) {
            leftRoot = leftRoot->left;
            leftHt++;
        }
        
        while(rightRoot) {
            rightRoot = rightRoot->right;
            rightHt++;
        }
        
        if(leftHt == rightHt) return pow(2, leftHt) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
        
        
//         // OR:
//         int count = 0;
//         queue<TreeNode* > q;
//         q.push(root);
        
//         while(!q.empty()) {
            
//             int n = q.size();
//             count += n;
            
//             while(n--) {
                
//                 TreeNode* current = q.front();
//                 q.pop();
                
//                 if(current->left) q.push(current->left);
//                 if(current->right) q.push(current->right);
                
//             }
            
//         }
        
//         return count;
    }
};