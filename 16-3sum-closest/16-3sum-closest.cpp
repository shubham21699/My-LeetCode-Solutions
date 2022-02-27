class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();
        if(n < 3) return 0;
        if(n == 3) return nums[0] + nums[1] + nums[2];
        
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int result = 0;
        
        for(int i=0 ; i<n-2 ; i++) {
            
            int j = i+1;
            int k = n-1;
            
            while(j < k) {
                
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target) return sum;
                
                if(diff > abs(sum - target)) {
                    result = sum;
                    diff = abs(sum - target);
                }
                if(sum > target) k--;
                else j++;
                
            }
            
        }
        
        return result;
    }
};