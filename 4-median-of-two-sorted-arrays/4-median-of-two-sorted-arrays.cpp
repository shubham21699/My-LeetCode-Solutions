class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        
        if(n > m) return findMedianSortedArrays(nums2, nums1);
        
        int low = 0;
        int high = n;
        
        while(low <= high) {
            
            int partitionNums1 = low + (high - low)/2;
            int partitionNums2 = (n + m + 1)/2 - partitionNums1;
            
            double left1 = (partitionNums1 == 0) ? INT_MIN : nums1[partitionNums1-1];
            double left2 = (partitionNums2 == 0) ? INT_MIN : nums2[partitionNums2-1];
            double right1 = (partitionNums1 == n) ? INT_MAX : nums1[partitionNums1];
            double right2 = (partitionNums2 == m) ? INT_MAX : nums2[partitionNums2];
            
            if(left1 <= right2 && left2 <= right1) {
                if((n + m) % 2 == 0) return (max(left1, left2) + min(right1, right2)) / 2;
                else return max(left1, left2);
            }
            else if(left1 > right2) high = partitionNums1 - 1;
            else low = partitionNums1 + 1;
            
        }
        
        return -1;
        
        
//         // OR - Divide and Conquer Approach:
//         vector<int> combine;
//         int i = 0;
//         int j = 0;
        
//         while(i < n && j < m) {
            
//             if(nums1[i] < nums2[j]) {
//                 combine.push_back(nums1[i]);
//                 i++;
//             }
//             else {
//                 combine.push_back(nums2[j]);
//                 j++;
//             }
            
//         }
        
//         while(i < n) {
//             combine.push_back(nums1[i]);
//             i++;
//         }
        
//         while(j < m) {
//             combine.push_back(nums2[j]);
//             j++;
//         }
        
//         double result = 0.0;
//         int k = combine.size();
        
//         if(k % 2 == 0) {
//             result = (combine[(k/2)-1] + combine[k/2]) / 2.0;
//         }
//         else result = combine[floor(k/2)];
        
//         return result;
    }
};