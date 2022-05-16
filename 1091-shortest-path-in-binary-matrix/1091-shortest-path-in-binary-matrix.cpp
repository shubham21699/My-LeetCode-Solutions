class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        if(n == 1) {
            if(grid[0][0] == 0) return 1;
            return -1;
        }
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        
        queue<pair<int, int>> q;
        q.push({ 0, 0 });
        grid[0][0] = 1;
        
        while(!q.empty()) {
            
            int size = q.size();
            
            while(size--) {
            
                auto p = q.front();
                q.pop();

                int i = p.first;
                int j = p.second;

                if(i == n-1 && j == n-1) return grid[i][j];

                if(i+1<n && j<n && i>=0 && j>=0 && grid[i+1][j] == 0) {
                    q.push({ i+1, j });
                    grid[i+1][j] = grid[i][j] + 1;
                }
                if(i<n && j+1<n && i>=0 && j>=0 && grid[i][j+1] == 0) {
                    q.push({ i, j+1 });
                    grid[i][j+1] = grid[i][j] + 1;
                }
                if(i<n && j<n && i-1>=0 && j>=0 && grid[i-1][j] == 0) {
                    q.push({ i-1, j });
                    grid[i-1][j] = grid[i][j] + 1;
                }
                if(i<n && j<n && i>=0 && j-1>=0 && grid[i][j-1] == 0) {
                    q.push({ i, j-1 });
                    grid[i][j-1] = grid[i][j] + 1;
                }
                if(i+1<n && j+1<n && i>=0 && j>=0 && grid[i+1][j+1] == 0) {
                    q.push({ i+1, j+1 });
                    grid[i+1][j+1] = grid[i][j] + 1;
                }
                if(i+1<n && j<n && i>=0 && j-1>=0 && grid[i+1][j-1] == 0) {
                    q.push({ i+1, j-1 });
                    grid[i+1][j-1] = grid[i][j] + 1;
                }
                if(i<n && j<n && i-1>=0 && j-1>=0 && grid[i-1][j-1] == 0) {
                    q.push({ i-1, j-1 });
                    grid[i-1][j-1] = grid[i][j] + 1;
                }
                if(i<n && j+1<n && i-1>=0 && j>=0 && grid[i-1][j+1] == 0) {
                    q.push({ i-1, j+1 });
                    grid[i-1][j+1] = grid[i][j] + 1;
                }

            }
            
        }
        
        return -1;
    }
};