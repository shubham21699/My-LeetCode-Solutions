class Solution {
    void find_next_permute(vector<vector<int> >& result, vector<int>& nums, int index, int n) {
        
        if(index >= n) {
            result.push_back(nums);
            return;
        }
        
        for(int i=index ; i<n ; i++) {
            swap(nums[index], nums[i]);
            find_next_permute(result, nums, index+1, n);
            swap(nums[index], nums[i]); // BACKTRACK
        }
        
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int> > result;
        
        if(n == 1) {
            result.push_back(nums);
            return result;
        }
        
        if(n == 2) {
            result.push_back(nums);
            reverse(nums.begin(), nums.end());
            result.push_back(nums);
            return result;
        }
        
        find_next_permute(result, nums, 0, n);
        return result;
    }
};