class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        int n = nums.size();
        long long result = 0;
        
        // For each nums[i] in A, we update several values
        // result is the maximum value of a triplet (A[i] - A[j]) * A[k].
        // maxab is the maximum value of pair A[i] - A[j]
        // maxa is the maximum value of element A[i].
        
        long long maxab = 0, maxa = 0;
        
        for(int i=0 ; i<n ; i++) {
            result = max(result, 1LL * maxab * nums[i]);
            maxab = max(maxab, maxa - nums[i]);
            maxa = max(maxa, 1LL * nums[i]);
        }
        
        // // OR: O(n^3)
        // for(int i=0 ; i<n-2 ; i++) {
        //     for(int j=i+1 ; j<n-1 ; j++) {
        //         for(int k=j+1 ; k<n ; k++) {
        //             long long val = (long long) (nums[i] - nums[j]) * nums[k];
        //             result = max(result, val);
        //         }
        //     }
        // }
        
        return result;
    }
};