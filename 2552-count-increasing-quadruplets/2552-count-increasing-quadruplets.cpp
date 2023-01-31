class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        
        int n = nums.size();
        long long count = 0;
        
        vector<vector<int>> left(n, vector<int>(n+1));
        vector<vector<int>> right(n, vector<int>(n+1));
        
        for(int i=1 ; i<n ; i++) {
            // New array will based on the old array
            left[i] = left[i-1];
            
            // Update all the elements greater than nums[i-1]
            for(int j=nums[i-1]+1 ; j<=n ; j++) {
                left[i][j]++;
            }
        }
        
        for(int i=n-2 ; i>=0 ; i--) {
            right[i] = right[i+1];
            for(int j=0 ; j<nums[i+1] ; j++) {
                right[i][j]++;
            }
        }
        
        for(int j=0 ; j<n ; j++) {
            for(int k=j+1 ; k<n ; k++) {
                if(nums[j] <= nums[k]) continue;
                
                // left[j][nums[k]] is the count of feasible i
                // right[k][nums[j]] is the count of feasible l
                count += left[j][nums[k]] * right[k][nums[j]];
            }
        }
        
        return count;
        
        
//         // OR: Will give TLE
//         for(int i=0 ; i<n-3 ; i++) {
//             for(int j=i+1 ; j<n-2 ; j++) {
//                 if(nums[i] < nums[j]) {
//                     for(int k=j+1 ; k<n-1 ; k++) {
//                         if(nums[k] < nums[j]) {
//                             for(int l=k+1 ; l<n ; l++) {
//                                 if(nums[i] < nums[k] && nums[k] < nums[j] && nums[j] < nums[l]) 
//                                     count++;
//                             }
//                         }
//                     }
//                 }
//             }
//         }
        
//         return count;
    }
};