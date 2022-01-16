class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(n == 1 && m == 1) {
            if(grid[0][0] == 0) return 0;
            if(grid[0][0] == 1) return -1;
            if(grid[0][0] == 2) return 0;
        }
        
        queue<pair<int, int> > q;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                // if(grid[i][j] == 1 && (grid[i+1][j] == 0) && (grid[i][j+1] == 0) && (grid[i-1][j] == 0) && grid[i][j-1] == 0) return -1;
                if(grid[i][j] == 2) q.push({ i, j });
            }
        }
        
        // if(q.size() == 0) return 0;
        
        int time = 0;
        
        while(!q.empty()) {
            
            int k = q.size();
            bool flag = false;
            
            while(k--) {
                
                pair<int, int> p = q.front();
                q.pop();
                int i = p.first;
                int j = p.second;
                
                if(i>=0 && i<n && j+1>=0 && j+1<m && grid[i][j+1] == 1) {
                    grid[i][j+1] = 2;
                    q.push({ i, j+1 });
                    flag = true;
                }
                if(i+1>=0 && i+1<n && j>=0 && j<m && grid[i+1][j] == 1) {
                    grid[i+1][j] = 2;
                    q.push({ i+1, j });
                    flag = true;
                }
                if(i>=0 && i<n && j-1>=0 && j-1<m && grid[i][j-1] == 1) {
                    grid[i][j-1] = 2;
                    q.push({ i, j-1 });
                    flag = true;
                }
                if(i-1>=0 && i-1<n && j>=0 && j<m && grid[i-1][j] == 1) {
                    grid[i-1][j] = 2;
                    q.push({ i-1, j });
                    flag = true;
                }
                
            }
            
            if(flag) time++;
        }
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                if(grid[i][j] == 1) return -1;
            }
        }
        
        return time;
    }
};