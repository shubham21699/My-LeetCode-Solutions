class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int, int> mp;
        long long sum = 0;
        long long maxSum = 0;
        int j = 0;
        
        for(int i=0 ; i<n ; i++) {
            sum += nums[i];
            mp[nums[i]]++;
            
            if(i-j == k-1) {
                if(mp.size() == k) maxSum = max(maxSum, sum);
                
                mp[nums[j]] == 1 ? mp.erase(nums[j]) : mp[nums[j]]--;
                sum -= nums[j];
                j++;
            }
            
        }
        
        return maxSum;
    }
};