class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        vector<int> result;
        unordered_map<int, int> mp;
        
        for(int i=0 ; i<n ; i++) mp[nums1[i]]++;
        
        for(int j=0 ; j<m ; j++) {
            if(mp[nums2[j]] > 0) {
                result.push_back(nums2[j]);
                mp[nums2[j]]--;
            }
        }
        
        return result;
    }
};