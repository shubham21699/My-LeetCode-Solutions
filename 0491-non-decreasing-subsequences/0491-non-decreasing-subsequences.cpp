class Solution {
public:
    void subsequences(vector<int>& nums, int index, int n, vector<int> v, set<vector<int>>& st) {
        
        if(v.size() >= 2) st.insert(v);
        
        for(int i=index ; i<n ; i++) {
             if(v.empty() || nums[i] >= v.back()) {
                v.push_back(nums[i]);
                subsequences(nums, i+1, n, v, st);
                v.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return {};
        
        set<vector<int>> st;
        vector<int> v;
        subsequences(nums, 0, n, v, st);
        
        vector<vector<int>> result;
        for(auto it : st) result.push_back(it);
        
        return result;
    }
};