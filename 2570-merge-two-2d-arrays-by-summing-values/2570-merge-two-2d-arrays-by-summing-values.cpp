class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> result;
        int i = 0, j = 0;
        
        while(i < n && j < m) {
            
            if(nums1[i][0] < nums2[j][0]) result.push_back(nums1[i++]);
            else if(nums2[j][0] < nums1[i][0]) result.push_back(nums2[j++]);
            else result.push_back({ nums1[i][0], nums1[i++][1] + nums2[j++][1] });
            
        }
        
        while(i < n) result.push_back(nums1[i++]);
        while(j < m) result.push_back(nums2[j++]);
        
        return result;
    }
};