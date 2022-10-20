class Solution {
public:
    int findMaxK(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return -1;
        
        unordered_set<int> st;
        int ans = -1;
        
        for(int i=0 ; i<n ; i++) {
            if(st.find(-nums[i]) != st.end()) ans = max(ans, abs(nums[i]));
            st.insert(nums[i]);
        }
        
        return ans;
    }
};