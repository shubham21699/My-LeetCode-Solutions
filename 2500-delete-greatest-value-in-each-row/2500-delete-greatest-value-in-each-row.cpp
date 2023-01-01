class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        if(n == 1 && m == 1) return grid[0][0];
        if(n == 1) return accumulate(grid[0].begin(), grid[0].end(), 0);
        
        for(int i=0 ; i<n ; i++) {
            sort(grid[i].rbegin(), grid[i].rend());
        }
        
        int result = 0;
        
        for(int j=0 ; j<m ; j++) {
            int val = 0;
            for(int i=0 ; i<n ; i++) {
                val = max(val, grid[i][j]);
            }
            
            result += val;
        }
        
        return result;
    }
};