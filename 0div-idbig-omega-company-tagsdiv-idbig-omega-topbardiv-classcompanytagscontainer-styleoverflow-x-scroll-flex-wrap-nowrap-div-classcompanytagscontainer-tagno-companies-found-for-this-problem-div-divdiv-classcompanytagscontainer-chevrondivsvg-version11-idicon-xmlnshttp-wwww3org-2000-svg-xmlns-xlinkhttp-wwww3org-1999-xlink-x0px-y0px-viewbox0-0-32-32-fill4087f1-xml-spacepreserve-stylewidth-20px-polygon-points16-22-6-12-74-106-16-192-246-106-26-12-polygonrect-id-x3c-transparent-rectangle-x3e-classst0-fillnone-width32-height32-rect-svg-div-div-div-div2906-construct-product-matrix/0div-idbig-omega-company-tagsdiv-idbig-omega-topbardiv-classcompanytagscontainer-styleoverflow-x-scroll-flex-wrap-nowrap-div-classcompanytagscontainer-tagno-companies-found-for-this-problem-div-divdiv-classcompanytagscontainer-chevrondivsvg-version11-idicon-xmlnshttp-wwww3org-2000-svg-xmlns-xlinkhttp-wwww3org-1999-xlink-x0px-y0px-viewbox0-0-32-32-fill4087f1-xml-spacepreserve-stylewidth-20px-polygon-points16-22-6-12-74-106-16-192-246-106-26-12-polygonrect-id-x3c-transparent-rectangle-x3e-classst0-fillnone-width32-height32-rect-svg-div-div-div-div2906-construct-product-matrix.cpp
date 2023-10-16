class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        long long prodTillNow = 1;
        vector<vector<int>> prefix(n, vector<int>(m, 1));
        vector<vector<int>> suffix(n, vector<int>(m, 1));
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                prefix[i][j] = prodTillNow;
                prodTillNow = (prodTillNow * grid[i][j]) % 12345;
            }
        }
        
        prodTillNow = 1;
        
        for(int i=n-1 ; i>=0 ; i--) {
            for(int j=m-1 ; j>=0 ; j--) {
                suffix[i][j] = prodTillNow;
                prodTillNow = (prodTillNow * grid[i][j]) % 12345;
            }
        }
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                grid[i][j] = (1LL * prefix[i][j] * suffix[i][j]) % 12345;
            }
        }
        
        return grid;
    }
};