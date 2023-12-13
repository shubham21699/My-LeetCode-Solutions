class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        vector<int> row1s(n), col1s(m);
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                if(mat[i][j] == 1) {
                    row1s[i]++;
                    col1s[j]++;
                }
            }
        }
        
        int result = 0;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                if(mat[i][j] == 1 && row1s[i] == 1 && col1s[j] == 1) result++;
            }
        }
        
        return result;
    }
};