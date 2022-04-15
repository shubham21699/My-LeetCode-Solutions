class Solution {
    void dfs(vector<vector<int>>& isConnected, unordered_map<int, bool>& visited, int i, int n) {
        
        visited[i] = true;
        
        for(int j=0 ; j<n ; j++) {
            if(!visited[j] && isConnected[i][j] == 1) dfs(isConnected, visited, j, n);
        }
        
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        if(n <= 1) return 1;
        
        unordered_map<int, bool> visited;
        int provinces = 0;
        
        for(int i=0 ; i<n ; i++) {
            if(!visited[i]) {
                provinces++;
                dfs(isConnected, visited, i, n);
            }
        }
        
        return provinces;
    }
};