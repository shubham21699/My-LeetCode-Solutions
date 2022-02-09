class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return false;
        if(n == 2) {
            if(nums[0] == nums[1]) return true;
            return false;
        }
        
        unordered_set<int> s;
        
        for(int i=0 ; i<n ; i++) {
            if(s.find(nums[i]) != s.end()) return true;
            s.insert(nums[i]);
        }
        
        return false;
    }
};