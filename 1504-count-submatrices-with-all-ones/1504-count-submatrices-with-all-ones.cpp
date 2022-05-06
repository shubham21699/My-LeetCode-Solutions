class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        int result = 0;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=1 ; j<m ; j++) {
                if(mat[i][j] == 0) continue;
                mat[i][j] = mat[i][j-1] + 1;
            }
        }
        
        for(int j=0 ; j<m ; j++) { // From left to right
            for(int i=0 ; i<n; i++) { // From top to bottom
                
                int mini = mat[i][j];
                
                for(int k=i ; k>=0 ; k--) { // From i to top ( count number of rectangles that can be made )
                    
                    // The number of rectangles that can be made with the right edge extended 
                    // from mat[i][j] to mat[k][j]
                    mini = min(mini, mat[k][j]);
                    if(mini == 0) break;
                    
                    result += mini;
                }
                
            }
        }

        return result;
    }
};