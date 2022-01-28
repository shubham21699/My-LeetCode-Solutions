class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        if(n == 1 && m == 1) {
            if(matrix[0][0] == '1') return 1;
            return 0;
        }
        
        if(n == 1) {
            int x = 0;
            for(int j=0 ; j<m ; j++) x += matrix[0][j]-'0';
            if(x >= 1) return 1;
            return 0;
        }
        
        if(m == 1) {
            int x = 0;
            for(int i=0 ; i<n ; i++) x += matrix[i][0]-'0';
            if(x >= 1) return 1;
            return 0;
        }
        
        if(n == 2 && m == 2) {
            int x = matrix[0][0]-'0' + matrix[0][1]-'0' + matrix[1][0]-'0' + matrix[1][1]-'0';
            if(x == 4) return 4;
            if(x == 0) return 0;
            return 1;
        }
        
        int result = 0;
        vector<vector<int> > dp(n, vector<int>(m, 0));
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                
                if(i==0 || j==0 || matrix[i][j] == '0') {
                    dp[i][j] = matrix[i][j]-'0';
                }
                else if(matrix[i][j] == '1') {
                    dp[i][j] = min({ dp[i-1][j], dp[i][j-1], dp[i-1][j-1] }) + 1;
                }
                
                result = max(result, dp[i][j]);
                
            }
        }
        
        return result*result;
    }
};