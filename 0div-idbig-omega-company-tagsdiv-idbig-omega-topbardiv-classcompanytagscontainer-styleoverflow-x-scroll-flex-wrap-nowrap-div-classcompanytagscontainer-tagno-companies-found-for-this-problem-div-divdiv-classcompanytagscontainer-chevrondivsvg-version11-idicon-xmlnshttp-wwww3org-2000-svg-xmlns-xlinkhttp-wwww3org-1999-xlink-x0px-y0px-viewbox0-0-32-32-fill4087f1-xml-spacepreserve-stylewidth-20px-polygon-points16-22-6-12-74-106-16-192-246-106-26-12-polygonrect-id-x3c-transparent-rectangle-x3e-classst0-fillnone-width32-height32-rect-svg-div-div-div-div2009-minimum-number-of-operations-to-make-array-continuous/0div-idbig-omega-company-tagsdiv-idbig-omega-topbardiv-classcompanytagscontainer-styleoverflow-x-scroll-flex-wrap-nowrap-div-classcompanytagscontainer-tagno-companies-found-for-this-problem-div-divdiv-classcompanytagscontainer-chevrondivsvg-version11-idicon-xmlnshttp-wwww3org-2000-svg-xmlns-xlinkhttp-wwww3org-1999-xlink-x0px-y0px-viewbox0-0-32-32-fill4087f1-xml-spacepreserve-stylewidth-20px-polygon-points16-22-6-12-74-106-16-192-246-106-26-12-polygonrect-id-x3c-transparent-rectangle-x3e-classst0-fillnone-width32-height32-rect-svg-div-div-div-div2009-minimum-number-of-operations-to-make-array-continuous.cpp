class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return 0;
        if(n == 2) return abs(nums[0] - nums[1]) == 1 ? 0 : 1;
        
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        
        int m = nums.size();
        int result = INT_MAX;
        
        for(int i=0 ; i<m ; i++) {
            int start = nums[i];
            int end = nums[i] + n - 1;
            
            int len = upper_bound(nums.begin(), nums.end(), end) - nums.begin();
            result = min(result, i + n - len);
        }
        
        return result;
    }
};