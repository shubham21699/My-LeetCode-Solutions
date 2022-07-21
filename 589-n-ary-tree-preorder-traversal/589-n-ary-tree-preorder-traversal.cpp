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
    void traverse(Node* root, vector<int>& res) {
        
        if(!root) return;
        
        vector<Node* > child = root->children;
        res.push_back(root->val);
        
        for(int i=0 ; i<child.size() ; i++) {
            traverse(child[i], res);
        }
        
    }
    
    vector<int> preorder(Node* root) {
        
        vector<int> res;
        if(!root) return res;
        if(root->children.empty()) {
            res.push_back(root->val);
            return res;
        }
        
        traverse(root, res);
        return res;
    }
};