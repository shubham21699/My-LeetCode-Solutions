class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        
        if(n == 0) {
            nums1 = nums2;
            return;
        }
        if(m == 0) return;
        
        int i = n-1;
        int j = m-1;
        int k = n+m-1;
        
        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                k--;
                i--;
            }
            else {
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }
        
        while(j >= 0) {
            nums1[k] = nums2[j];
            k--;
            j--;
        }
        
        
/////////////////// OR /////////////////////////         
//         vector<int> inc(n+m, 0);
        
//         int i = 0;
//         int j = 0;
//         int k = 0;
        
//         while(i < n && j < m) {
//             if(nums1[i] < nums2[j]) {
//                 inc[k] = nums1[i];
//                 k++;
//                 i++;
//             }
//             else {
//                 inc[k] = nums2[j];
//                 k++;
//                 j++;
//             }
//         }
        
//         while(i < n) {
//             inc[k] = nums1[i];
//             k++;
//             i++;
//         }
        
//         while(j < m) {
//             inc[k] = nums2[j];
//             k++;
//             j++;
//         }
        
//         for(int i=0 ; i<k ; i++) {
//             nums1[i] = inc[i];
//         }
        
        
    }
};