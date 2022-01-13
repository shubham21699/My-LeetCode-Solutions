class Solution {
    // int nx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
    // int ny[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    
    bool isSafe(int x, int y, int n) {
        
        if(x >=0 && x < n && y >=0 && y < n) return true;
        return false;
    }
    
    unordered_map<int, unordered_map<int, unordered_map<int, double> > > dp;
    
public:
    double knightProbability(int n, int k, int row, int column) {
        
        if(!isSafe(row, column, n)) return 0;
        if(dp.count(row) && dp[row].count(column) && dp[row][column].count(k)) return dp[row][column][k];
        if(k == 0) return 1;
        
        double total_possible = knightProbability(n, k-1, row-2, column+1) 
                                + knightProbability(n, k-1, row-1, column+2) 
                                + knightProbability(n, k-1, row+1, column+2) 
                                + knightProbability(n, k-1, row+2, column+1) 
                                + knightProbability(n, k-1, row+2, column-1) 
                                + knightProbability(n, k-1, row+1, column-2) 
                                + knightProbability(n, k-1, row-1, column-2) 
                                + knightProbability(n, k-1, row-2, column-1);
        
        dp[row][column][k] = total_possible / 8.0;
        return dp[row][column][k];
        
        
        
////////////////// OR ////////////////////////////
//         vector<vector<vector<double>> > dp(n, vector<vector<double> >(n, vector<double>(k+1, 0)));
        
//         for(int i=0 ; i<n ; i++) {
//             for(int j=0 ; j<n ; j++) {
//                 dp[i][j][0] = 1;
//             }
//         }
        
//         for(int steps=1 ; steps<=k ; steps++) {
            
//             for(int i=0 ; i<n ; i++) {
//                 for(int j=0 ; j<n ; j++) {
                    
//                     double prob = 0.0;

//                     for(int dir=0 ; dir<8 ; dir++) {

//                         int newRow = i + nx[dir];
//                         int newCol = j + ny[dir];
                        
//                         if(isSafe(newRow, newCol, n)) {
//                             prob += (dp[newRow][newCol][steps-1] / 8.0);                     
//                         }

//                     }

//                     dp[i][j][steps] = prob;
//                 }
//             }
//         }
        
//         return dp[row][column][k];
    }
};