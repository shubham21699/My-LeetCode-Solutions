class Solution {
    int n, m;
    vector<vector<bool>> pacific, atlantic;
    vector<vector<int>> result;
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j) {
        
        if(visited[i][j]) return;
        
        visited[i][j] = true;
        
        // If cell reachable from both the oceans, insert into final answer vector.
        if(atlantic[i][j] && pacific[i][j]) result.push_back({ i, j });
        
        // DFS from current cell only if height of next cell is greater.
        if(i+1<n && heights[i+1][j] >= heights[i][j]) dfs(heights, visited, i+1, j);
        if(j+1<m && heights[i][j+1] >= heights[i][j]) dfs(heights, visited, i, j+1);
        if(i-1>=0 && heights[i-1][j] >= heights[i][j]) dfs(heights, visited, i-1, j);
        if(j-1>=0 && heights[i][j-1] >= heights[i][j]) dfs(heights, visited, i, j-1);
        
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        n = heights.size();
        m = heights[0].size();
        
        pacific = atlantic = vector<vector<bool>>(n, vector<bool>(m, false));
        
        // Perform dfs from all edge cells (ocean-connected cells).
        for(int i=0 ; i<n ; i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, m-1);
        }
        
        for(int j=0 ; j<m ; j++) {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, n-1, j);
        }
        
        return result;
    }   
};