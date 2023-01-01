class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        
        int n = nums.size();
        if(n < 2) return -1;
        
        sort(nums.begin(), nums.end());
        if(n == 2) return (long long) nums[0]*nums[0] == nums[1] ? 2 : -1;
        
        unordered_set<long long> st;
        for(int i=0 ; i<n ; i++) st.insert(nums[i]);
        
        int result = 0;
        
        for(int i=0 ; i<n-2 ; i++) {
            int count = 1;
            long long val = nums[i];
            
            while(st.find((long long) val*val) != st.end()) {
                count++;
                val *= val;
            }
            
            result = max(result, count);
        }
        
        return result < 2 ? -1 : result;
    }
};