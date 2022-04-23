class Solution {
    int dfs(vector<vector<int>>& stones, vector<bool>& visited, int index, int n) {
        
        visited[index] = true; // Mark current point as visited.
        int res = 0;
        
        for(int i=0 ; i<n ; i++) {
            if(!visited[i] && (stones[index][0] == stones[i][0] || stones[index][1] == stones[i][1])) {
                // Increamenting by 1 will add no. of points visiting is the no. of points to be deleted.
                res += (1 + dfs(stones, visited, i, n)); 
            }
        }
        
        return res;
    }
    
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();
        if(n == 1) return 0;
        
        vector<bool> visited(n, false);
        int result = 0;
        
        for(int i=0 ; i<n ; i++) {
            if(!visited[i]) {
                result += dfs(stones, visited, i, n);
            }
        }
        
        return result;
    }
};