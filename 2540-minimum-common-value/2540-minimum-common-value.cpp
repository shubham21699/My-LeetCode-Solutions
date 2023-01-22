class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        unordered_set<int> st(nums1.begin(), nums1.end());
        
        for(int i=0 ; i<m ; i++) {
            if(st.find(nums2[i]) != st.end()) return nums2[i];
        }
        
        return -1;
    }
};