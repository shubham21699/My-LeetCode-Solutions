class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 2) {
            swap(nums[0], nums[1]);
            return nums;
        }
        
        vector<int> result(n, 0);
        int count0 = count(nums.begin(), nums.end(), 0);
        if(count0 > 1) return result;
        
        int product = 1;
        
        for(int i=0 ; i<n ; i++) {
            if(nums[i] == 0) continue;
            product *= nums[i];
        }
        
        for(int i=0 ; i<n ; i++) {
            
            if(count0 == 1) {
                if(nums[i] == 0) result[i] = product;
                else result[i] = 0;
            }
            else result[i] = product / nums[i];
            
        }
        
        return result;
        
//         OR: Will give TLE
//         for(int i=0 ; i<n ; i++) {
//             int product = 1;
//             for(int j=0 ; j<n ; j++) {
//                 if(i == j) continue;
//                 product *= nums[j];
//             }
//             result[i] = product;
//         }
        
//         return result;
    }
};