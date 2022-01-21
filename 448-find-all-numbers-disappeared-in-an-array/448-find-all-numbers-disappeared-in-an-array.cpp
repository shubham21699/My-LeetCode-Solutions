class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        int n = nums.size();
        unordered_set<int> s;
        
        for(int i=0 ; i<n ; i++) {
            s.insert(nums[i]);
        }
        
        vector<int> result;
        for(int i=1 ; i<=n ; i++) {
            if(s.find(i) == s.end()) result.push_back(i);
        }
        
        return result;
    }
};