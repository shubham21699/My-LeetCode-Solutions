class Solution {
public:
    void find(vector<vector<int>>& mat, int n, int m, int cols, int i, vector<bool>& visited, int& result) {
        
        // If required number of columns are picked
        if(cols == 0 || i == m) {
            
            int count = 0;
            
            for(int i=0 ; i<n ; i++) {
                
                bool check = true;
                
                for(int j=0 ; j<m ; j++) {
                    if(mat[i][j] == 1 && !visited[j]) {
                        check = false;
                        break;
                    }
                }
                
                if(check) count++;
            }
            
            result = max(result, count);
            return;
        }
        
        visited[i] = true; // Pick this column
        find(mat, n, m, cols-1, i+1, visited, result);
        
        visited[i] = false; // Not pick this column
        find(mat, n, m, cols, i+1, visited, result);
    }
    
    int maximumRows(vector<vector<int>>& mat, int cols) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<bool> visited(m);
        int result = 0;
        find(mat, n, m, cols, 0, visited, result);
        
        return result;
    }
};