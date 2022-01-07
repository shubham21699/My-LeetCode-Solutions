class TreeAncestor {
public:
    vector<vector<int> > dp;
    
    TreeAncestor(int n, vector<int>& parent) {
        
        dp.assign(n, vector<int>(25, -1));
        
        for(int i=0 ; i<n ; i++) {
            // Initializing 2^0th parent of node i with immediate parent of node i
            dp[i][0] = parent[i];
        }
        
        for(int j=1 ; j<25 ; j++) {
            for(int i=0 ; i<n ; i++) {
                // check if there exists a 2^(j-1)th parent of node i
                if(dp[i][j-1] != -1) {
                    // If yes, then make 2^(j-1)th as jth parent of node i
                    int parent = dp[i][j-1];
                    dp[i][j] = dp[parent][j-1];
                }
            }
        }
        
    }
    
    int getKthAncestor(int node, int k) {
        
        int parent = node;
        
        // Traverse up in the tree in powers of 2 and break if no ancestor exists above it
        while(k > 0) {
            
            if(parent == -1) break;
            
            int im = log2(k);
            parent = dp[parent][im];
            k -= pow(2, im);
            
        }
        
        return parent;
        
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */