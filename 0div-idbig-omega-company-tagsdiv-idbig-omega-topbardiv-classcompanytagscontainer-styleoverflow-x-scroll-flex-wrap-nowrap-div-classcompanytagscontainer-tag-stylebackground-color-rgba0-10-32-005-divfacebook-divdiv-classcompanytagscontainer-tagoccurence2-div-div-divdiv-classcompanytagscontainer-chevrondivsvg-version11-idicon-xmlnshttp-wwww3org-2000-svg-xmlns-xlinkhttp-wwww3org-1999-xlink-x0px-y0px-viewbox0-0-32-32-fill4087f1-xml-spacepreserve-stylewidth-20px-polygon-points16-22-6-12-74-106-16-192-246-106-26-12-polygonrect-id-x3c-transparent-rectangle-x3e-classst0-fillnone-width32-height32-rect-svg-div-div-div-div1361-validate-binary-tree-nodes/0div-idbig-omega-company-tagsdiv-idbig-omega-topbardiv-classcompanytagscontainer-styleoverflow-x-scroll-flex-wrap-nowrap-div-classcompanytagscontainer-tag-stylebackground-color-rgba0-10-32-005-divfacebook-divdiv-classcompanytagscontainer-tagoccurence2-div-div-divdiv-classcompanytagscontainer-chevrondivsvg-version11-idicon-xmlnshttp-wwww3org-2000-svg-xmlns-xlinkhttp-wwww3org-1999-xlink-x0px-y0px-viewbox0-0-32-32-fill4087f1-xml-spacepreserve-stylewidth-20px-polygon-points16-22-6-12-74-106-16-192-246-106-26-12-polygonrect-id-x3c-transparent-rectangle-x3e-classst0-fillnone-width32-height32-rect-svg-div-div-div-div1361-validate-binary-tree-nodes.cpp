class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        vector<vector<int>> parent(n);
        
        // Storing parent(s) of each node, node with no parent will be the root node of tree.
        for(int i=0 ; i<n ; i++) {
            if(leftChild[i] != -1) parent[leftChild[i]].push_back(i);
            if(rightChild[i] != -1) parent[rightChild[i]].push_back(i);
        }
        
        int rootExists = -1; // Get the root node
        
        for(int i=0 ; i<n ; i++) {
            if(parent[i].size() > 1) return false; // Node having more than 1 parent
            if(rootExists >= 0 && parent[i].size() == 0) return false; // 1 root node already exists
            
            if(parent[i].size() == 0) rootExists = i; // Root node
        }
        
        if(rootExists == -1) return false; // No root node
        
        queue<int> q;
        q.push(rootExists);
        int countNodes = 0;
        
        // Count number of nodes traversed from root node.
        while(!q.empty()) {
            
            int curr = q.front();
            q.pop();
            countNodes++;
            
            if(leftChild[curr] != -1) q.push(leftChild[curr]);
            if(rightChild[curr] != -1) q.push(rightChild[curr]);
            
        }
        
        return countNodes == n;
    }
};