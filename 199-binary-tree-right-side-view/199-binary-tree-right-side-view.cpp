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
    void rightView(TreeNode* root, int level, vector<int>& result) {
        
        if(!root) return;
        if(level > result.size()) result.push_back(root->val);
        
        rightView(root->right, level+1, result);
        rightView(root->left, level+1, result);
        
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        
        if(!root) return {};
        if(!root->left && !root->right) return { root->val };
        
        // DFS:
        vector<int> result;
        rightView(root, 1, result);
        
        return result;
        
//         // OR: BFS
//         vector<int> result;
//         queue<TreeNode* > q;
//         q.push(root);
        
//         while(!q.empty()) {
            
//             int n = q.size();
//             result.push_back(q.front()->val);
            
//             while(n--) {
                
//                 TreeNode* current = q.front();
//                 q.pop();
                
//                 if(current->right) q.push(current->right);
//                 if(current->left) q.push(current->left);
                
//             }
            
//         }
        
//         return result;
    }
};