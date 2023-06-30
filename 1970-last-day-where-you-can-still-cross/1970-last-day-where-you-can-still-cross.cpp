class Solution {
public:
    bool isPossible(int row, int col, int target, vector<vector<int>>& cells) {
        
        vector<vector<int>> grid(row+1, vector<int>(col+1, 0));
        vector<pair<int, int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // Possible directions
        
        for(int i=0 ; i<target ; i++) {
            grid[cells[i][0]][cells[i][1]] = 1;
        }
        
        queue<pair<int, int>> q;
        
        for(int i=1 ; i<=col ; i++) {
            if(grid[1][i] == 0) {
                q.push({1, i}); // Start BFS from the top row
                grid[1][i] = 1; // Mark the cell as visited
            }
        }
        
        while(!q.empty()) {
            
            auto p = q.front();
            q.pop();
            
            for(auto d : directions) {
                
                int newrow = p.first + d.first;
                int newcol = p.second + d.second;
                
                if(newrow > 0 && newrow <= row && newcol > 0 && newcol <= col && grid[newrow][newcol] == 0) {
                    if(newrow == row) return true;
                    
                    grid[newrow][newcol] = 1;
                    q.push({ newrow, newcol });
                }
                
            }
            
        }
        
        return false;
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        int n = cells.size();
        int m = cells[0].size();
        int left = 0, right = row*col, latestPossibleDay = 0;
        
        while(left <= right) {
            
            int mid = left + (right - left)/2;
            
            if(isPossible(row, col, mid, cells)) {
                left = mid+1;
                latestPossibleDay = mid;
            }
            else right = mid-1;
            
        }
        
        return latestPossibleDay;
    }
};