class Solution {
public:    
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        int n = nums.size();
        int m = queries.size();
        sort(nums.begin(), nums.end());
        vector<int> ans(m, 0);
        
        for(int i=1 ; i<n ; i++) nums[i] += nums[i-1];
        
        for(int j=0 ; j<m ; j++) {
            
            if(nums.back() <= queries[j]) {
                ans[j] = n;
                continue;
            }
            
            for(int i=0 ; i<n ; i++) {
                if(nums[i] > queries[j]) break;
                ans[j] = i+1;
            }
        }
        
        return ans;
    }
};