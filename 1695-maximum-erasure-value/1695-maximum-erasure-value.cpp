class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int i = 0;
        int score = 0;
        int sum = 0;
        unordered_set<int> st;
        
        for(int j=0 ; j<n ; j++) {
            if(st.find(nums[j]) != st.end()) {
                score = max(score, sum);
                
                while(st.find(nums[j]) != st.end() && i<j) {
                    st.erase(nums[i]);
                    sum -= nums[i];
                    i++;
                }
    
            }
            
            st.insert(nums[j]);
            sum += nums[j];
        }
        
        score = max(score, sum);
        return score;
    }
};