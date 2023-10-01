class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int> mp;
        
        for(int i=0 ; i<n ; i++) {
            mp[nums[i]]++;
        }
        
        int count = 0;
        
        for(auto it=mp.begin() ; it!=mp.end() ; it++) {
            if(it->second == 1) return -1;
            
            count += ceil(it->second / 3.0);
        }
        
        return count;
    }
};