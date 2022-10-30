class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        
        int n = nums.size();
        unordered_map<int, int> mp;
        int result = INT_MAX;
        int maxCount = 0;
        
        for(int i=0 ; i<n ; i++) {
            int x = nums[i] % space;
            mp[x]++;
            maxCount = max(maxCount, mp[x]);
        }
        
        for(int i=0 ; i<n ; i++) {
            int x = nums[i] % space;
            if(mp[x] == maxCount) result = min(result, nums[i]);
        }
        
        return result;
    }
};