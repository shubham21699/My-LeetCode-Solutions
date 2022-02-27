class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(k <= 1) return 0;
        if(n == 1) return nums[0];
        
        int count = 0;
        int product = 1;
        
        for(int i=0, j=0 ; j<n ; j++) {
            
            product *= nums[j];
            
            // If prosuct >= k, Move window's left index to right so that product is less than k again.
            while(product >= k && i < n) {
                product /= nums[i];
                i++;
            }
            
            // This is the length of the subarray containing products less than k. 
            count += (j - i + 1);
             
        }
        
        return count;
    }
};