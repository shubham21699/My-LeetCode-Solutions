class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
        int n = img.size();
        int m = img[0].size();
        if(n == 0 || m == 0) return {{}};
        
        vector<vector<int>> result(n, vector<int>(m));
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                
                int sum = img[i][j];
                int cellsCount = 1;
                
                for(int k=0 ; k<8 ; k++) {
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    
                    if(x < 0 || y < 0 || x >= n || y >= m) continue;
                    
                    sum += img[x][y];
                    cellsCount++;
                }
                
                result[i][j] = sum / cellsCount;
            }
        }
        
        return result;
    }
};