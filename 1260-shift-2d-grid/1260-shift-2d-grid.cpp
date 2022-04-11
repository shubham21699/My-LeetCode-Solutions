class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(k == 0 || (n*m) == k) return grid;
        
        vector<vector<int>> result(n, vector<int>(m, 0));
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                
                int newInd = (i*m + j);
                int newIndex = (newInd + k) % (n*m);
                int newR = newIndex / m;
                int newC = newIndex % m;
                
                result[newR][newC] = grid[i][j];
            }
        }
     
        return result;
    }
};