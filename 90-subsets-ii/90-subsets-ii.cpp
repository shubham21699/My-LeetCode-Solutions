class Solution {
    void subset(vector<int>& nums, vector<vector<int>>& result, vector<int> v, int index, int n) {
        
        result.push_back(v);
        
        for(int i=index ; i<n ; i++) {
            v.push_back(nums[i]);
            
            subset(nums, result, v, i+1, n);
            
            v.pop_back(); // Backtrack
        }
        
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) {
            return { {}, {nums[0]} };
        }
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        vector<int> v;
        subset(nums, result, v, 0, n);
        
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};