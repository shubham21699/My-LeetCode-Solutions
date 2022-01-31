class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        
        // Divide and Conquer Approach:
        vector<int> combine;
        int i = 0;
        int j = 0;
        
        while(i < n && j < m) {
            if(nums1[i] < nums2[j]) {
                combine.push_back(nums1[i]);
                i++;
            }
            else {
                combine.push_back(nums2[j]);
                j++;
            }
        }
        
        while(i < n) {
            combine.push_back(nums1[i]);
            i++;
        }
        
        while(j < m) {
            combine.push_back(nums2[j]);
            j++;
        }
        
        double result;
        int k = combine.size();
        
        if(k % 2 == 0) {
            result = (combine[(k/2)-1] + combine[k/2]) / 2.0;
        }
        else result = combine[floor(k/2)];
        
        return result;
    }
};