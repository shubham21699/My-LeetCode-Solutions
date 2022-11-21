class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int n = maze.size();
        int m = maze[0].size();
        
        queue<vector<int>> q;
        q.push({ entrance[0], entrance[1], 0 });
        vector<vector<bool>> visited(n, vector<bool>(m));
        visited[entrance[0]][entrance[1]] = true;
        
        while(!q.empty()) {
            
            int size = q.size();
            
            while(size--) {
                
                auto current = q.front();
                int i = current[0];
                int j = current[1];
                int dist = current[2];
                q.pop();
                
                if((i != entrance[0] || j != entrance[1]) && (i == 0 || j == 0 || i == n-1 || j == m-1))
                    return dist;
                
                if(i<n-1 && maze[i+1][j] == '.' && !visited[i+1][j]) {
                    q.push({ i+1, j, dist+1 });
                    visited[i+1][j] = true;
                }
                if(j<m-1 && maze[i][j+1] == '.' && !visited[i][j+1]) {
                    q.push({ i, j+1, dist+1 });
                    visited[i][j+1] = true;
                }
                if(i>0 && maze[i-1][j] == '.' && !visited[i-1][j]) {
                    q.push({ i-1, j, dist+1 });
                    visited[i-1][j] = true;
                }
                if(j>0 && maze[i][j-1] == '.' && !visited[i][j-1]) {
                    q.push({ i, j-1, dist+1 });
                    visited[i][j-1] = true;
                }
                
            }
            
        }
        
        return -1;
    }
};