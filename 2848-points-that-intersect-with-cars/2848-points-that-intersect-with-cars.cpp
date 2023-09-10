class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        
        int n = nums.size();
        unordered_set<int> st;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=nums[i][0] ; j<=nums[i][1] ; j++) st.insert(j);
        }
        
        return st.size();
    }
};