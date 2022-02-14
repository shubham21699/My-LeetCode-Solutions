/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if(!root) return NULL;
        if(!root->left && !root->right) return root;
        
        queue<Node* > q;
        if(root->left) q.push(root->left);
        if(root->right) q.push(root->right);
        
        while(!q.empty()) {
            
            int n = q.size();
            
            while(n--) {
                
                Node* current = q.front();
                q.pop();
                if(n>=1) current->next = q.front();
                
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
                
            }
            
        }
        
        return root;
    }
};