class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size();
        long long countInc = 0;
        long long countDec = 0;
        
        for(int i=0 ; i<n ; i++) {
            if(nums1[i] != nums2[i]) {
                if(k == 0) return -1;
                if(abs(nums1[i] - nums2[i]) % k != 0) return -1;
                
                if(nums1[i] > nums2[i]) countDec += abs(nums1[i] - nums2[i]) / k;
                else countInc += abs(nums1[i] - nums2[i]) / k;
            }
        }
        
        return countInc == countDec ? countInc : -1;
    }
};