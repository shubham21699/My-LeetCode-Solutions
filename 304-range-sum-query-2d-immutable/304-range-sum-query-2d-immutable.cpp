class NumMatrix {
    vector<vector<int>> grid;
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        grid = vector<vector<int>>(n+1, vector<int>(m+1, 0));
        
        for(int i=1 ; i<=n ; i++) {
            for(int j=1 ; j<=m ; j++) {
                grid[i][j] = matrix[i-1][j-1] + grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        return grid[row1][col1] - grid[row1][col2+1] - grid[row2+1][col1] + grid[row2+1][col2+1];
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */