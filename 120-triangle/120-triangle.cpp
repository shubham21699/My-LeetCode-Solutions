class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        if(n == 1) return triangle[0][0];
        if(n == 2) return triangle[0][0] + min(triangle[1][0], triangle[1][1]);
        
        for(int i=1 ; i<n ; i++) {
            for(int j=0 ; j<=i ; j++) {
                if(j == 0) triangle[i][j] += triangle[i-1][j];
                else if(j == i) triangle[i][j] += triangle[i-1][j-1];
                else triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
        
        return *min_element(triangle[n-1].begin(), triangle[n-1].end());
    }
};