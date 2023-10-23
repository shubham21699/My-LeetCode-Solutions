class Solution {
public:
    int minimumSum(vector<int>& nums) {
        
        int n = nums.size();
        int result = INT_MAX;
        vector<int> rightMin = nums;
        
        for(int i=n-2 ; i>=0 ; i--) {
            rightMin[i] = min(rightMin[i], rightMin[i+1]);
        }
        
        int leftMin = nums[0];
        
        for(int i=1 ; i<n-1 ; i++) {
            if(nums[i] > leftMin && nums[i] > rightMin[i]) {
                result = min(result, leftMin + nums[i] + rightMin[i]);
            }
            
            leftMin = min(leftMin, nums[i]);
        }
        
        return result == INT_MAX ? -1 : result;
        
//         // OR: Will give TLE
//         for(int i=0 ; i<n-2 ; i++) {
//             for(int j=i+1 ; j<n-1 ; j++) {
//                 for(int k=j+1 ; k<n ; k++) {
//                     if(nums[i] < nums[j] && nums[k] < nums[j]) {
//                         result = min(result, nums[i] + nums[j] + nums[k]);
//                     }
//                 }
//             }
//         }
        
//         return result == INT_MAX ? -1 : result;
    }
};