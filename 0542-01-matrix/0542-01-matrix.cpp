class Solution {
public:
    vector<vector<int>> dir = {{ -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 }};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int, int>> q;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                if(mat[i][j] == 0) q.push({ i, j });
                else mat[i][j] = -1;
            }
        }
        
        while(!q.empty()) {
            
            auto curr = q.front();
            q.pop();
            
            for(int k=0 ; k<4 ; k++) {
                int x = curr.first + dir[k][0];
                int y = curr.second + dir[k][1];
                
                if(x >= 0 && y >= 0 && x < n && y < m && mat[x][y] == -1) {
                    q.push({ x, y });
                    mat[x][y] = mat[curr.first][curr.second] + 1;
                }
            }
            
        }
        
        return mat;
    }
};