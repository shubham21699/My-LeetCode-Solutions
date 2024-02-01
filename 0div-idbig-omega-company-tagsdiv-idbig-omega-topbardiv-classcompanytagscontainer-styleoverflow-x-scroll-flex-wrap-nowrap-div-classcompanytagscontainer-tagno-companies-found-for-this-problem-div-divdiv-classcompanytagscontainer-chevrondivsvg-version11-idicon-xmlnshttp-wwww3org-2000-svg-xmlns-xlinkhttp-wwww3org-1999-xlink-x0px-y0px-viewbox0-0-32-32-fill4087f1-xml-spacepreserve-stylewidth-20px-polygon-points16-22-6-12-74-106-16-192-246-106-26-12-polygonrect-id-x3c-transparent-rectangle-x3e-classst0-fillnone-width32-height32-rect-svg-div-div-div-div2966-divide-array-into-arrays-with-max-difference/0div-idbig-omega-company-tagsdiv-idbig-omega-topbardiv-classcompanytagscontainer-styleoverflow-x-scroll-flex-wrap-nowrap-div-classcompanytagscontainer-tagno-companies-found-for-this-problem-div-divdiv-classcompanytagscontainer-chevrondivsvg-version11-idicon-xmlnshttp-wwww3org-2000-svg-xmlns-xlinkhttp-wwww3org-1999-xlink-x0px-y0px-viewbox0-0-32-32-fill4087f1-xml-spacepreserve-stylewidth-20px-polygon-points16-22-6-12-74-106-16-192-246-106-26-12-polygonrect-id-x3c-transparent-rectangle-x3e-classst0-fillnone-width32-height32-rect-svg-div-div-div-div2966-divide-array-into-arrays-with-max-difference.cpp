class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(n < 3) return {};
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        
        for(int i=0 ; i<n-2 ; i+=3) {
            if(nums[i+2]-nums[i] <= k) result.push_back({ nums[i], nums[i+1], nums[i+2] });
            else return {};
        }
        
        return result;
    }
};