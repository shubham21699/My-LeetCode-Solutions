class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int no_of_rows = matrix.size();
        int no_of_cols = matrix[0].size();
        int i = 0;
        int j = 0;
        
        while(i < no_of_rows/2 && j < no_of_cols/2) {
         
            int k = i;
            int l = j;
            
            while(l < no_of_cols-1-k) {
                int temp1 = matrix[k][l];
                int temp2 = matrix[l][no_of_cols-1-k];
                int temp3 = matrix[no_of_rows-1-k][no_of_cols-1-l];
                int temp4 = matrix[no_of_rows-1-l][k];

                matrix[l][no_of_cols-1-k] = temp1;
                matrix[no_of_rows-1-k][no_of_cols-1-l] = temp2;
                matrix[no_of_rows-1-l][k] = temp3;
                matrix[k][l] = temp4;
                
                l++;
            }
            
            i++;
            j++;
            // no_of_rows--;
            // no_of_cols--;
            
        }
        
    }
};