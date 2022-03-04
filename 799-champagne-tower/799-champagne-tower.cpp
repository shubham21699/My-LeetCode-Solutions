class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        if(poured == 0) return 0;
        if(query_row == 0 && query_glass == 0) return 1.0;
        
        vector<vector<double>> result(101, vector<double>(101, 0.0));
        result[0][0] = poured;
        
        for(int i=0 ; i<=query_row ; i++) {
            for(int j=0 ; j<=i ; j++) {
                if(result[i][j] >= 1) {
                    // Split  (result[i][j] - 1) into next level
                    result[i+1][j] += (result[i][j] - 1) / 2.0;
                    result[i+1][j+1] += (result[i][j] - 1) / 2.0;
                    result[i][j] = 1;
                }
            }
        } 
        
        return result[query_row][query_glass];
    }
};