class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_set<double> st;
        
        while(n > 0) {
            double avg = (nums[0] + nums.back()) / 2.0;
            nums.pop_back();
            nums.erase(nums.begin());
            st.insert(avg);
            n -= 2;
        }
        
        return st.size();
    }
};