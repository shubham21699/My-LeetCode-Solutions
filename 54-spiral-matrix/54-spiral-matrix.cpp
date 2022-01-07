class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
         int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> result;
        
        if(n == 1) {
            for(int j=0 ; j<m ; j++) result.push_back(matrix[0][j]);
            
            return result;
        }
        
        if(m == 1) {
            for(int i=0 ; i<n ; i++) result.push_back(matrix[i][0]);
            
            return result;
        }
        
        int i = 0;
        int j = 0;
        
        while(i < n && j < m) {
            
            int k = i;
            int l = j;
            while(l < m) {
                result.push_back(matrix[k][l]);
                l++;
            }
            i++;
            
            k = i;
            l--;
            while(k < n) {
                result.push_back(matrix[k][l]);
                k++;
            }
            m--;
            
            
            if(i < n) {
                k--;
                l--;
                while(l >= j) {
                    result.push_back(matrix[k][l]);
                    l--;
                }
                n--;
            }
            
            
            if(j < m) {
                k--;
                l++;
                while(k >= i) {
                    result.push_back(matrix[k][l]);
                    k--;
                }
                j++;
            }
        
            
        }
        
        return result;
        
    }
};