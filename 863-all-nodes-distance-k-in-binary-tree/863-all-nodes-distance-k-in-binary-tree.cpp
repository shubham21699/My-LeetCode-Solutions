/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<TreeNode*, TreeNode* > mp;
    
    void storeParent(TreeNode* root) {
        
        queue<TreeNode* > q;
        q.push(root);
        
        while(!q.empty()) {
            
            TreeNode* parent = q.front();
            q.pop();
            
            // If current node is the root node that storing its parrent as NULL
            if(parent == root) {
                mp[parent] = NULL;
            }
            
            // If left child of popped node exists, then store its parent as value and node as key
            if(parent->left) {
                mp[parent->left] = parent;
                q.push(parent->left);
            }
            
            // If right child of popped node exists, then store its parent as value and node as key
            if(parent->right) {
                mp[parent->right] = parent;
                q.push(parent->right);
            }
            
        }
        
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        if(!root->left && !root->right) return {};
        storeParent(root);
        
        vector<int> result;
        unordered_set<TreeNode* > s;
        int distance = 0;
        queue<TreeNode* > q;
        q.push(target);
        s.insert(target);
        
        while(!q.empty()) {
            
            // If distance equals to k, then we found a node which is at distance k from target node
            if(distance == k) {
                while(!q.empty()) {
                    result.push_back(q.front()->val);
                    q.pop();
                }
                break;
            }
            
            int n = q.size();
            
            // BFS on nodes left, right and parent node:
            while(n--) {
                
                TreeNode* current_node = q.front();
                q.pop();
                
                // If left of the node is not visited yet, then push it in queue and insert it in set
                if(current_node->left && s.find(current_node->left) == s.end()) {
                    q.push(current_node->left);
                    s.insert(current_node->left);
                }
                
                // If right of the node is not visited yet, then push it in queue and insert it in set
                if(current_node->right && s.find(current_node->right) == s.end()) {
                    q.push(current_node->right);
                    s.insert(current_node->right);
                }
                
                // If parent of the node is not visited yet, then push it in queue and insert it in set
                if(mp[current_node] && s.find(mp[current_node]) == s.end()) {
                    q.push(mp[current_node]);
                    s.insert(mp[current_node]);
                }
                
            }
            
            distance++;
        }
        
        return result;
    }
};