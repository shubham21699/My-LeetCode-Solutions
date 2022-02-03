class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        int n = nums1.size();
        if(n == 1) {
            if((nums1[0] + nums2[0] + nums3[0] + nums4[0]) == 0) return 1;
            return 0;
        }
        
        unordered_map<int, int> m;
        int count = 0;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<n ; j++) {
                m[nums1[i] + nums2[j]]++;
            }
        }
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<n ; j++) {
                count += m[-(nums3[i] + nums4[j])];
            }
        }
        
        return count;
    }
};