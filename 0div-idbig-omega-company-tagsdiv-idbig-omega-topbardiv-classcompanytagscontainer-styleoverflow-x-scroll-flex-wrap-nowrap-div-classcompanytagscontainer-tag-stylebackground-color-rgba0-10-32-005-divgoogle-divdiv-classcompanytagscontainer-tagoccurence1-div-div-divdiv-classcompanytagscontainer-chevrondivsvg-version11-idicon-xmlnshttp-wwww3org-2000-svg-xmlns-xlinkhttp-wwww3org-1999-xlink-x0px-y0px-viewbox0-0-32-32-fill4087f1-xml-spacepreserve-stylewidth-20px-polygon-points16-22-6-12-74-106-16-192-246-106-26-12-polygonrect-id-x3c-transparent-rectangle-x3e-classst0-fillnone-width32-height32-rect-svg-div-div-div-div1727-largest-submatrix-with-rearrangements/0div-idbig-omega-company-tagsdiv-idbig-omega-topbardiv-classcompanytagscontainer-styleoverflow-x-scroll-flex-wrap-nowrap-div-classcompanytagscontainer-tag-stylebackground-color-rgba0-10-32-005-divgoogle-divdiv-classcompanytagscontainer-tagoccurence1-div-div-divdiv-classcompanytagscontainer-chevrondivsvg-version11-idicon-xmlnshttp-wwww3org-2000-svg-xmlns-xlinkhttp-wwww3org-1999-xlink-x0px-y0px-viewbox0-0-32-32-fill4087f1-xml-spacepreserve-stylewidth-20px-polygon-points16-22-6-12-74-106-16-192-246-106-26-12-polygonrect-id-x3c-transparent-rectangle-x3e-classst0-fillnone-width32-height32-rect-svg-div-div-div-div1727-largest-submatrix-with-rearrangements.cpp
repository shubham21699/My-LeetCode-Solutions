class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m);
        int result = 0;
        
        // View each row and its above as pillars 
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                if(matrix[i][j] == 1) height[j]++;
                else height[j] = 0;
            }
            
            // Sort pillars
            vector<int> rowHeight = height;
            sort(rowHeight.begin(), rowHeight.end());

            // Iterate to get the maxium rectangle
            for(int j=0 ; j<m ; j++) {
                result = max(result, rowHeight[j] * (m-j));
            }

        }
        
        return result;
    }
};