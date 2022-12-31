class Solution {
public:
    int paths(vector<vector<int>>& grid, int i, int j, int n, int m, int emptyBoxes, set<pair<int, int>> visited) {
        
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == -1) return 0;
        if(visited.find({ i, j }) != visited.end()) return 0;
        
        visited.insert({ i, j });
        if(grid[i][j] == 2 && visited.size() == emptyBoxes) return 1;
        
        return paths(grid, i+1, j, n, m, emptyBoxes, visited) + paths(grid, i, j+1, n, m, emptyBoxes, visited) +
            paths(grid, i-1, j, n, m, emptyBoxes, visited) + paths(grid, i, j-1, n, m, emptyBoxes, visited);
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int starti = -1, startj = -1;
        int noOfObstacles = 0;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                if(grid[i][j] == 1) {
                    starti = i;
                    startj = j;
                }
                if(grid[i][j] == -1) noOfObstacles++;
            }
        }
        
        int totalBoxes = n*m;
        int emptyBoxes = totalBoxes - noOfObstacles;
        set<pair<int, int>> visited;
        
        return paths(grid, starti, startj, n, m, emptyBoxes, visited);
    }
};