class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(n == 1) return 0;
        
        unordered_map<int, int> m;
        for(int i=0 ; i<n ; i++) m[nums[i]]++;
        
        int count = 0;
        
        for(auto it=m.begin() ; it!=m.end() ; it++) {
            if(k == 0) {
                if(it->second > 1) count++;
            }
            else if(m.find(it->first + k) != m.end()) count++;
        }
        
        return count;
    }
};