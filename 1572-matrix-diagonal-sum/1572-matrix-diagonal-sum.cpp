class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int n = mat.size();
        if(n == 1) return mat[0][0];
        int sum = 0;
        
        for(int i=0 ; i<n ; i++) {
            if(n % 2 != 0 && i == n/2) sum += mat[i][i];
            else sum += mat[i][i] + mat[i][n-i-1];
        }
        
        return sum;
    }
};