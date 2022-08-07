class Solution {
public:    
    long long countBadPairs(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, long long> mp;
        
        long long count = 0; // Count Good Pairs
        
        for(int i=0 ; i<n ; i++) {
            
            if(mp.find(i-nums[i]) != mp.end()) {
                count += mp[i-nums[i]];
            }
            
            mp[i-nums[i]]++;
        }
        
        // Subtract Good Pairs from Total Pairs to get Bad Pairs
        return (long long) n*(n-1)/2 - count;
    }
};