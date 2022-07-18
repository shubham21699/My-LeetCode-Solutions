class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        if(n == 1 && m == 1) return matrix[0][0] == target;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=1 ; j<m ; j++) {
                matrix[i][j] += matrix[i][j-1];
            }
        }
        
        unordered_map<int, int> mp;
        int count = 0;
        
        for(int i=0 ; i<m ; i++) {
            for(int j=i ; j<m ; j++) {
                
                mp = {{ 0, 1 }};
                int curr = 0;
                
                for(int k=0 ; k<n ; k++) {
                    curr += matrix[k][j] - (i>0 ? matrix[k][i-1] : 0);
                    count += mp.find(curr - target) != mp.end() ? mp[curr - target] : 0;
                    mp[curr]++;
                }
                
            }
        }
        
        return count;
    }
};