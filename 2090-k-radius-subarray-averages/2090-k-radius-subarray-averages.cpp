class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(k == 0) return nums;
        
        vector<int> result(n, -1);
        int window = 2*k + 1;
        if(n < window) return result;
        
        long long sum = 0;
        
        for(int i=0 ; i<n ; i++) {
            sum += nums[i];
            
            if(i - window >= 0) sum -= nums[i - window];
            
            if(i >= window-1) result[i-k] = sum / window;
        }
        
        return result;
    }
};