class Solution {
    void find(vector<int>& nums, vector<vector<int> >& result, vector<int>& v, int index, int n) {
        
        result.push_back(v);
        
        for(int i=index ; i<n ; i++) {
            v.push_back(nums[i]);
            find(nums, result, v, i+1, n);
            v.pop_back();
        }
        
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int> > result;
        vector<int> v;
        
        if(n == 1) {
            result.push_back(v);
            result.push_back(nums);
            return result;
        }
         
        find(nums, result, v, 0, n);
        return result;
    }
};