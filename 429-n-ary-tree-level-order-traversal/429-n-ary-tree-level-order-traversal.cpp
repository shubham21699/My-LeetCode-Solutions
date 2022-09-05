/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        if(!root) return {};
        
        vector<vector<int>> result;
        queue<Node* > q;
        q.push(root);
        
        while(!q.empty()) {
            
            int n = q.size();
            vector<int> v;
            
            while(n > 0) {
                
                Node* current = q.front();
                q.pop();
                
                v.push_back(current->val);
                
                for(auto child : current->children) {
                    q.push(child);
                }
                
                n--;
            }
         
            result.push_back(v);
        }
        
        return result;
    }
};