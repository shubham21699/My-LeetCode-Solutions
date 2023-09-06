class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        
        int n = nums.size();
        unordered_map<int, int> mp;
        long long count = 0;
        int total = 0;
        mp[0] = 1;
        
        for(int i=0 ; i<n ; i++) {
            total = (total + (nums[i] % modulo == k ? 1 : 0)) % modulo;
            count += mp[(total - k + modulo) % modulo];
            mp[total]++;
        }
         
        return count;
    }
};