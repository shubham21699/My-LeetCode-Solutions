class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        if(n == 1 && m == 1) return matrix[0][0];
        
        int result = INT_MIN;
        
        for(int i=0 ; i<m ; i++) {
            
            vector<int> rowSums(n, 0);
            
            for(int j=i ; j<m ; j++) {
                
                // Using Kadane's Algorithm:
                int max_sum_so_far = INT_MIN;
                int curr_sum = 0;
                
                for(int k=0 ; k<n ; k++) {
                    rowSums[k] += matrix[k][j];
                    
                    curr_sum = max(curr_sum + rowSums[k], rowSums[k]);
                    max_sum_so_far = max(max_sum_so_far, curr_sum);
                }
                
                if(max_sum_so_far <= k) {
                    result = max(result, max_sum_so_far);
                    continue;
                }
                
                // Finding the max subarray no more than K using Kadane's Algorithm:
                max_sum_so_far = INT_MIN;
                curr_sum = 0;
                set<int> s;
                s.insert(0);
                
                for(auto sum : rowSums) {
                    curr_sum += sum;
                    auto it = s.lower_bound(curr_sum - k);
                    if(it != s.end()) max_sum_so_far = max(max_sum_so_far, curr_sum - *it);
                    
                    s.insert(curr_sum);
                }
                
                result = max(result, max_sum_so_far);
            }
            
        }
        
        return result;
    }
};