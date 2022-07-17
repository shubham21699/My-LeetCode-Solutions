class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return { 0, 1 };
        unordered_map<int, int> mp;
        
        for(int i=0 ; i<n ; i++) {
            mp[nums[i]]++;
        }
        
        int pairs = 0;
        int left = 0;
        
        for(auto it=mp.begin() ; it!=mp.end() ; it++) {
            pairs += it->second/2;
            left += it->second%2;
        }
        
        return { pairs, left };
    }
};