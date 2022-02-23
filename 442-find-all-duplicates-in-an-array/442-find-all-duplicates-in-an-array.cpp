class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        unordered_set<int> s;
        vector<int> result;
        
        for(int i=0 ; i<n ; i++) {
            if(s.find(nums[i]) != s.end()) result.push_back(nums[i]);
            else s.insert(nums[i]);
        }
        
        return result;
    }
};