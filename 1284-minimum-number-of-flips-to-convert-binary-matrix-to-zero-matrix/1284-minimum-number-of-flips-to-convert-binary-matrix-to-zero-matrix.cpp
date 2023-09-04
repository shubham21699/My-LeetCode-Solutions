class Solution {
public:
    vector<vector<int>>& flip(vector<vector<int>>& mat, int i, int j, int n, int m) {
        
        mat[i][j] ^= 1;
        
        if(i-1 >= 0) mat[i-1][j] ^= 1;
        if(j-1 >= 0) mat[i][j-1] ^= 1;
        if(i+1 < n) mat[i+1][j] ^= 1;
        if(j+1 < m) mat[i][j+1] ^= 1;
        
        return mat;
    }
    
    bool isZeroMat(vector<vector<int>>& mat, int n, int m) {
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                if(mat[i][j] == 1) return false;
            }
        }
        
        return true;
    }
    
    int flipOrNoFlip(vector<vector<int>> mat, int i, int j, int n, int m) {
        
        if(i == n) j++, i=0;
        if(j == m) return isZeroMat(mat, n, m) ? 0 : 100000;
        
        int res1 = flipOrNoFlip(mat, i+1, j, n, m);
        int res2 = 1 + flipOrNoFlip(flip(mat, i, j, n, m), i+1, j, n, m);
        
        return min(res1, res2);
    }
    
    int minFlips(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        if(n == 1 && m == 1) return mat[0][0] == 1;
        
        int result = flipOrNoFlip(mat, 0, 0, n, m);
        return result >= 100000 ? -1 : result;
    }
};