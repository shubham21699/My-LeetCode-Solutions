class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        if(n == 1) return {{ 1 }};
        vector<vector<int>> result(n, vector<int>(n, 0));
        
        int x = 1;
        int i = 0;
        int j = 0;
        int k = n-1;
        int l = n-1;
        
        while(i <= k && j <= l) {
            
            for(int c=j ; c<=l ; c++) {
                result[i][c] = x++;
            }
            i++;
            
            for(int r=i ; r<=k ; r++) {
                result[r][l] = x++;
            }
            l--;
            
            if(j <= l) {
                for(int c=l ; c>=j ; c--) {
                    result[k][c] = x++;
                }
                k--;
            }
            
            if(i <= k) {
                for(int r=k ; r>=i ; r--) {
                    result[r][j] = x++;
                }
                j++;
            }
            
        }
        
        return result;
    }
};