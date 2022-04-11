class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int i = 0;
        int j = m-1;
        int count = 0;
        
        while(i<n && i>=0 && j<m && j>=0) {
            
            if(grid[i][j] < 0) {
                count += (n-i); // Count number of elements < 1 in that column. 
                // If current element is < 1, then all elements below that are < 1.
                j--;
            }
            else i++;
            
        }
        
        return count;
    }
};