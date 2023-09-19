class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        
        int n = nums.size();
        long long result = 0;
        
        for(int i=1 ; i<=n ; i++) {
            long long sum = 0;
            
            for(int k=1 ; (i*k*k) <= n ; k++) {
                sum += nums[(i*k*k)-1];
            }

            result = max(result, sum);
        }
        
        return result;
    }
};