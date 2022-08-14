class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>> result;
        
        for(int i=0 ; i<n-2 ; i++) {
            vector<int> v;
            for(int j=0 ; j<n-2 ; j++) {
                
                int maxVal = max({ grid[i][j], grid[i][j+1], grid[i][j+2], 
                                   grid[i+1][j], grid[i+1][j+1], grid[i+1][j+2],
                                   grid[i+2][j], grid[i+2][j+1], grid[i+2][j+2] });
                
                v.push_back(maxVal);
            }
            
            result.push_back(v);
        }
        
        return result;
    }
};