class Solution {
    int score(vector<int>& a, vector<int>& b, int n) {
        
        // USING KADANE's ALGORITHM:
        int sum = accumulate(a.begin(), a.end(), 0);
        int maxi = 0;
        int runningSum = 0;
        
        for(int i=0 ; i<n ; i++) {
            runningSum += b[i] - a[i];
            if(runningSum < 0) runningSum = 0;
            
            maxi = max(maxi, runningSum);
        }
        
        return sum + maxi;
    }
    
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        if(n == 1) return max(nums1[0], nums2[0]);
       
        return max(score(nums1, nums2, n), score(nums2, nums1, n));
    }
};