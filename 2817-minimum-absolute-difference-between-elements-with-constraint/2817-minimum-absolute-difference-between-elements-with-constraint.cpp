class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        
        int n = nums.size();
        int result = INT_MAX;
        set<int> st;
        
        for(int i=x ; i<n && result>0 ; i++) {
            st.insert(nums[i-x]);
            auto it = st.upper_bound(nums[i]);
            if(it != st.end()) result = min(result, abs(nums[i] - *it)); // Check the difference with the greater element than nums[i]
            if(it != st.begin()) result = min(result, abs(nums[i] - *prev(it))); // Check the difference with the smaller element than nums[i]
        }
        
        
        // // OR: Will give TLE
        // for(int i=0 ; i<n-x ; i++) {
        //     for(int j=i+x ; j<n ; j++) {
        //         result = min(result, abs(nums[i] - nums[j]));
        //     }
        // }
        
        return result;
    }
};