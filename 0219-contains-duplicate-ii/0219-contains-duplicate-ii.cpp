class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(n == 1) return false;
        if(n == 2) return nums[0] == nums[1];
        
        unordered_map<int, int> mp;
        
        for(int i=0 ; i<n ; i++) {
            if(mp.find(nums[i]) != mp.end() && abs(i - mp[nums[i]]) <= k) return true;
            
            mp[nums[i]] = i;
        }
        
        return false;
    }
};