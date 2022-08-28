class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        // Firstly sort the diagonals starting from 1st row and all columns of 1st row
        for(int col=0 ; col<m ; col++) {
            priority_queue<int, vector<int>, greater<int>> pq;
            
            int i = 0;
            int j = col;
            
            while(i < n && j < m) {
                pq.push(mat[i][j]);
                i++;
                j++;
            }
            
            i = 0;
            j = col;
            
            while(i < n && j < m) {
                mat[i][j] = pq.top();
                pq.pop();
                i++;
                j++;
            }
            
        }
        
        // Then sort the diagonals starting from 2nd row and 1st col of each row
        for(int row=1 ; row<n ; row++) {
            priority_queue<int, vector<int>, greater<int>> pq;
            
            int i = row;
            int j = 0;
            
            while(i < n && j < m) {
                pq.push(mat[i][j]);
                i++;
                j++;
            }
            
            i = row;
            j = 0;
            
            while(i < n && j < m) {
                mat[i][j] = pq.top();
                pq.pop();
                i++;
                j++;
            }
            
        }
        
        return mat;
    }
};