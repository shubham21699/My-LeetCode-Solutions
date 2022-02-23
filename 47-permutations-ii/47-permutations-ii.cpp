class Solution {
    void permute(vector<int>& nums, vector<vector<int>>& result, int index, int n) {
        
        if(index >= n-1) {
            result.push_back(nums);
            return;
        }
        
        for(int i=index ; i<n ; i++) {
            if(i != index && nums[i] == nums[index]) continue;
            
            swap(nums[index], nums[i]);
            
            permute(nums, result, index+1, n);
            
            swap(nums[index], nums[i]); // Backtrack
        }
        
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return { nums };
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        permute(nums, result, 0, n);
        
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};