/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node* > newGraph;
    
public:
    Node* cloneGraph(Node* node) {
        
        if(!node) return NULL;
        
        // DFS:
        if(newGraph.find(node) == newGraph.end()) {
            
            newGraph[node] = new Node(node->val, {});
            
            for(Node* neighbor: node->neighbors) {
                newGraph[node] -> neighbors.push_back(cloneGraph(neighbor));
            }
            
        }
        
        return newGraph[node];   
    }
};