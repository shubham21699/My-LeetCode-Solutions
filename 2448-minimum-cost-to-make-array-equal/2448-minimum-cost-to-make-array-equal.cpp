class Solution {
public:    
    long long isMin(vector<int>& nums, vector<int>& cost, int val, int n) {
        
        long long costToGet = 0;
        
        for(int i=0 ; i<n ; i++) {
            costToGet += (long long) abs(val - nums[i]) * cost[i];
        }
        
        return costToGet;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        int n = nums.size();
     
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        long long minPossCost = 0;
        
        while(left < right) {
            
            int mid = left + (right - left)/2;
            long long val1 = isMin(nums, cost, mid, n);
            long long val2 = isMin(nums, cost, mid+1, n);
            
            minPossCost = min(val1, val2);
            
            if(val1 < val2) right = mid;
            else left = mid+1;
            
        }
        
        return minPossCost;
    }
};