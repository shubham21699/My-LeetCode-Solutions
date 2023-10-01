class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_set<int> st;
        int i = n-1;
        
        while(i >= 0 && st.size() != k) {
            if(nums[i] <= k) st.insert(nums[i]);
            i--;
        }
        
        return n-i-1;
    }
};