class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        
        int n = nums.size();
        unordered_map<int, int> mp;
        long long sum = 0, result = 0;
        int j = 0;
        
        for(int i=0 ; i<n ; i++) {
            sum += nums[i];
            mp[nums[i]]++;
            
            if(i >= k-1) {
                if(mp.size() >= m) result = max(result, sum);
                sum -= nums[j];
                mp[nums[j]] == 1 ? mp.erase(nums[j]) : mp[nums[j]]--;
                j++;
            }
        }
        
        return result;
    }
};