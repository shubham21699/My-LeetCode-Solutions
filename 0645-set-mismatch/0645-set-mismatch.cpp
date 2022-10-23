class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> res(2);
        unordered_set<int> st;
        
        for(int i=0 ; i<n ; i++) {
            if(st.find(nums[i]) != st.end()) res[0] = nums[i];
            st.insert(nums[i]);
        }
        
        for(int i=1 ; i<=n ; i++) {
            if(st.find(i) == st.end()) {
                res[1] = i;
                break;
            }
        }
        
        return res;
    }
};