class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        queue<pair<int, int>> q;
        int count0 = 0, count1 = 0;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(grid[i][j] == 0) count0++;
                else if(grid[i][j] == 1) {
                    count1++;
                    q.push({ i, j });
                }
            }
        }
        
        if(count0 == n*n || count1 == n*n) return -1;
        
        int distance = 0;
        
        while(!q.empty()) {
            
            int k = q.size();
            distance++;
            
            while(k--) {
                
                auto currentLand = q.front();
                q.pop();
                int i = currentLand.first;
                int j = currentLand.second;
                    
                grid[i][j] = distance;
                
                if(i+1<n && grid[i+1][j] == 0) {
                    q.push({ i+1, j });
                    grid[i+1][j] = distance+1;
                }
                if(j+1<n && grid[i][j+1] == 0) {
                    q.push({ i, j+1 });
                    grid[i][j+1] = distance+1;
                }
                if(i-1>=0 && grid[i-1][j] == 0) {
                    q.push({ i-1, j });
                    grid[i-1][j] = distance+1;
                }
                if(j-1>=0 && grid[i][j-1] == 0) {
                    q.push({ i, j-1 });
                    grid[i][j-1] = distance+1;
                }
                
            }
            
        }
        
        return distance-1;
    }
};