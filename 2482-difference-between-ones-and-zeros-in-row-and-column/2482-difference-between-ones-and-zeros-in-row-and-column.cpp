class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0 ; i<n ; i++) {
            int rowSum = 0;
            for(int j=0 ; j<m ; j++) {
                 rowSum += grid[i][j];
            }
            
            // Adding 1 column at end which stores count of 1 in each row
            grid[i].push_back(rowSum);
        }
        
        // Adding 1 row at end which stores count of 1 in each column
        grid.push_back(vector<int>(m+1));
        
        for(int j=0 ; j<m ; j++) {
            int colSum = 0;
            for(int i=0 ; i<n ; i++) {
                 colSum += grid[i][j];
            }
            
            grid[n][j] = colSum;
        }
        
        vector<vector<int>> diff(n, vector<int>(m));
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                
                int onesRowi = grid[i][m];
                int onesColj = grid[n][j];
                int zerosRowi = m - onesRowi;
                int zerosColj = n - onesColj;
                
                diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj;
            }
        }
     
        return diff;
    }
};