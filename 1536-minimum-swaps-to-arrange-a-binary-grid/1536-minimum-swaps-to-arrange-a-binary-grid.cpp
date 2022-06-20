class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<int> v(n);
        
        for(int i=0 ; i<n ; i++) {
            int j = n-1;
            int count0 = 0; // Zeroes at end of each row
            
            while(j>=0 && grid[i][j] == 0) {
                j--;
                count0++;
            }
            
            v[i] = count0;
        }
        
        int result = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            int requiredZeroes = n-1-i;
            
            if(v[i] < requiredZeroes) {
                
                int j = i;
                while(j < n && v[j] < requiredZeroes) {
                    j++;
                }
                
                // Means we do not find any row which satisfies our required number of zeroes condition.
                if(j == n) return -1;
                
                // If we find that row, then swap
                while(i < j) {
                    swap(v[j], v[j-1]);
                    j--;
                    result++;
                }
                
            }
            
        }
        
        return result;
    }
};