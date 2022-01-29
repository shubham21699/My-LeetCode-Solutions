class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        if(n == 1 && m == 1) {
            if(matrix[0][0] == target) return true;
            return false;
        }
        
        if(n == 2 && m == 2) {
            if(matrix[0][0]==target || matrix[0][1]==target || matrix[1][0]==target || matrix[1][1]==target)
                return true;
            return false;
        }
        
        int row = 0;
        int col = m-1;
        
        while(row < n && col >= 0) {
            
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) row++;
            else col--;
            
        }
        
        return false;
    }
};