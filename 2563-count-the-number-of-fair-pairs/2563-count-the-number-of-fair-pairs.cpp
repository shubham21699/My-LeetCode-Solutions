class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long count = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            int low = lower - nums[i];
            int high = upper - nums[i];
            int start = lower_bound(nums.begin()+i+1, nums.end(), low) - nums.begin();
            int end = upper_bound(nums.begin()+i+1, nums.end(), high) - nums.begin();
            
            count += (end - start);
        }
        
        return count;
    }
};