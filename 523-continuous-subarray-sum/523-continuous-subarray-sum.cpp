class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(n == 1) return false;
        if(n == 2) return (nums[0] + nums[1]) % k == 0;
        
        unordered_map<int, int> mp;
        int prefixSum = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            prefixSum += nums[i];
            if(k != 0) prefixSum %= k;
            
            if(prefixSum == 0 && i>0) return true;
            
            if(mp.find(prefixSum) != mp.end()) {
                if(i - mp[prefixSum] > 1) return true;
            }
            else mp[prefixSum] = i;
        }
        
        return false;
    }
};