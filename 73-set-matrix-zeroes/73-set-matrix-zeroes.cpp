class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        bool row1st = false;
        bool col1st = false;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                if(matrix[i][j] == 0) {
                    if(i == 0) row1st = true;
                    if(j == 0) col1st = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i=1 ; i<n ; i++) {
            for(int j=1 ; j<m ; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        
        if(row1st) {
            for(int j=0 ; j<m ; j++) {
                matrix[0][j] = 0;
            }
        }
        
        if(col1st) {
            for(int i=0 ; i<n ; i++) {
                matrix[i][0] = 0;
            }
        }
        
//         OR:
//         unordered_set<int> r;
//         unordered_set<int> c;
        
//         for(int i=0 ; i<n ; i++) {
//             for(int j=0 ; j<m ; j++) {
//                 if(matrix[i][j] == 0) {
//                     r.insert(i);
//                     c.insert(j);
//                 }
//             }
//         }
        
//         for(int i=0 ; i<n ; i++) {
//             for(int j=0 ; j<m ; j++) {
//                 if(r.find(i) != r.end() || c.find(j) != c.end()) matrix[i][j] = 0;
//             }
//         }
        
    }
};