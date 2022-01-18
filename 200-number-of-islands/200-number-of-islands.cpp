class Solution {
    void BFS(vector<vector<char> >& grid, vector<vector<bool> >& visited, int i, int j, int n, int m) {
        
        queue<pair<int, int> > q;
        q.push({ i, j });
        visited[i][j] = true;
        
        while(!q.empty()) {
            
            pair<int, int> p = q.front();
            q.pop();
            i = p.first;
            j = p.second;
            
            if(i+1<n && grid[i+1][j] == '1' && !visited[i+1][j]) {
                visited[i+1][j] = true;
                q.push({ i+1, j });
            }
            if(j+1<m && grid[i][j+1] == '1' && !visited[i][j+1]) {
                visited[i][j+1] = true;
                q.push({ i, j+1 });
            }
            if(i-1>=0 && grid[i-1][j] == '1' && !visited[i-1][j]) {
                visited[i-1][j] = true;
                q.push({ i-1, j });
            }
            if(j-1>=0 && grid[i][j-1] == '1' && !visited[i][j-1]) {
                visited[i][j-1] = true;
                q.push({ i, j-1 });
            }
            
        }
        
    }
    
    void DFS(vector<vector<char> >& grid, vector<vector<bool> >& visited, int i, int j, int n, int m) {
        
        visited[i][j] = true;
        
        if(i+1<n && grid[i+1][j] == '1' && !visited[i+1][j]) DFS(grid, visited, i+1, j, n, m);
        if(j+1<m && grid[i][j+1] == '1' && !visited[i][j+1]) DFS(grid, visited, i, j+1, n, m);
        if(i-1>=0 && grid[i-1][j] == '1' && !visited[i-1][j]) DFS(grid, visited, i-1, j, n, m);
        if(j-1>=0 && grid[i][j-1] == '1' && !visited[i][j-1]) DFS(grid, visited, i, j-1, n, m);
        
    }
    
public:
    int numIslands(vector<vector<char> >& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int count = 0;
        vector<vector<bool> > visited(n, vector<bool>(m, false));
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    DFS(grid, visited, i, j, n, m);
                    // OR: BFS will take more memory
                    // BFS(grid, visited, i, j, n, m);
                    count++;
                }
            }
        }
        
        return count;
    }
};