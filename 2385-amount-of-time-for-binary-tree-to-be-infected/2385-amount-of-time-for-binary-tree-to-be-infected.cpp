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
    TreeNode* getStartNode(TreeNode *root, int start){
        
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty()){
            
            int n = q.size();
            
            while(n > 0) {
                
                TreeNode *curr = q.front();
                q.pop();
                
                if(curr->val == start) return curr;
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                
                n--;
            }
        }
        
        return NULL;
    }

    
    void findPar(TreeNode* root, unordered_map<TreeNode*, TreeNode* >& parent) {
        
        if(!root) return;
        
        if(root->left) parent[root->left] = root;
        if(root->right) parent[root->right] = root;
        
        findPar(root->left, parent);
        findPar(root->right, parent);
    }
    
    int amountOfTime(TreeNode* root, int start) {
        
        unordered_map<TreeNode* , TreeNode* > parent;
        parent[root] = NULL;
        findPar(root, parent);
        
        queue<TreeNode* > q;
        TreeNode* startNode = getStartNode(root, start);
        q.push(startNode);
    
        unordered_map<TreeNode*, bool> visited;
        visited[startNode] = true;
        
        int time = 0;
        
        while(!q.empty()) {
            
            int n = q.size();
            
            while(n > 0) {
                
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if(curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if(curr != root && !visited[parent[curr]]) {
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                }
                
                n--;
            }
            
            time++;
        }
        
        return time-1;
    }
};