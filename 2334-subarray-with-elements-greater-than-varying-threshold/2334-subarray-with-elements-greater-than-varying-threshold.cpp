class Solution {
    int DivAndConq(vector<int>& nums, int l, int r, int threshold) {
        
        if(l > r) return 0;
        
        int minVal = threshold / (r-l+1);
        
        for(int i=l ; i<=r ; i++) {
            
            // Means this element cannot be part of any subarray, so find subarray to its left and right.
            if(nums[i] <= minVal) {
                
                int leftRes = DivAndConq(nums, l, i-1, threshold);
                if(leftRes) return leftRes;
                
                int rightRes = DivAndConq(nums, i+1, r, threshold);
                if(rightRes) return rightRes;
                
                // Else we don;t have result in this subarray.
                return 0;
            }
            
        }
        
        return r-l+1;
    }
    
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        if(maxi > threshold) return 1;
        
        int res = DivAndConq(nums, 0, n-1, threshold);
        return res ? res : -1;
        
//         //OR: Will give TLE
//         int size = 1;
        
//         while(size <= threshold) {
            
//             int x = threshold / size;
//             int j = 0;
            
//             for(int i=0 ; i<n ; i++) {
                
//                 if(i-j+1 == size) {
//                     if(*min_element(nums.begin() + j, nums.begin() + i + 1) > x) return size;
//                     j++;
//                 } 
                
//             }
            
//             size++;
//         }
     
//         return -1;
    }
};