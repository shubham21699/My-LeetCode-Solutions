class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        
        vector<vector<int>> result(n, vector<int>(n, 0));
        int q = queries.size();
        
        for(int k=0 ; k<q ; k++) {
            int r1 = queries[k][0];
            int c1 = queries[k][1];
            int r2 = queries[k][2];
            int c2 = queries[k][3];
            
            for(int i=r1 ; i<=r2 ; i++) {
                result[i][c1]++;
                if(c2+1 < n) result[i][c2+1]--;
            }
            
        }
        
        for(int i=0 ; i<n ; i++) {
            for(int j=1 ; j<n ; j++) {
                result[i][j] += result[i][j-1];
            }
        }
        
//         // OR:
//         for(int k=0 ; k<q ; k++) {
//             int r1 = queries[k][0];
//             int c1 = queries[k][1];
//             int r2 = queries[k][2];
//             int c2 = queries[k][3];
            
//             for(int i=r1 ; i<=r2 ; i++) {
//                 for(int j=c1 ; j<=c2 ; j++) {
//                     result[i][j] += 1;
//                 }
//             }
            
//         }
        
        return result;
    }
};