class Solution {
public:
    int capability(vector<int>& nums, int money, int i, int n, int k) {
        
        if(k == 0) return money;
        if(i >= n) return INT_MAX;
        
        return min(capability(nums, max(money, nums[i]), i+2, n, k-1), capability(nums, money, i+1, n, k));
    }
    
    int minCapability(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int ans = 0;
        
        while(low <= high) {
            
            int mid = low + (high - low) / 2;
            int taken = 0;
            
            for(int i=0 ; i<n ; i++) {
                if(mid >= nums[i]) {
                    taken++;
                    i++;
                }
            }
            
            if(taken >= k) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
            
        }
        
        return ans;
        
        
        // // OR: Will give TLE
        // return capability(nums, 0, 0, n, k);
    }
};