class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();
        int q = queries.size();
        vector<int> result;
        
        int sum = 0;
        for(int i=0 ; i<n ; i++) {
            if(nums[i] % 2 == 0) sum += nums[i];
        }
        
        for(int i=0 ; i<q ; i++) {
            
            int val = queries[i][0];
            int ind = queries[i][1];
            
            if(nums[ind] % 2 == 0) sum -= nums[ind];
            
            if((nums[ind]+val) % 2 == 0) {
                sum += nums[ind] + val;
            }
            
            nums[ind] += val;
            result.push_back(sum);
        }
        
        return result;
        
        
//         // OR: Brute Force
//         for(int i=0 ; i<q ; i++) {
            
//             nums[queries[i][1]] += queries[i][0];
            
//             int sum = 0;
//             for(int j=0 ; j<n ; j++) {
//                 if(nums[j] % 2 == 0) sum += nums[j];
//             }
            
//             result.push_back(sum);
//         }
        
//         return result;
    }
};