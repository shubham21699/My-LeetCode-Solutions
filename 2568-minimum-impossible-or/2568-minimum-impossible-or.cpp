class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        
        int result = 1;
        
        while(st.find(result) != st.end()) {
            result *= 2;
        }
        
        return result;
    }
};