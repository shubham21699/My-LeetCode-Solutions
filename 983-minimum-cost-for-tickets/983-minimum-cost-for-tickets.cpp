class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n = days.size();
        unordered_set<int> st(days.begin(), days.end());
        vector<int> dp(30, 0);
        
        for(int i=days[0] ; i<=days.back() ; i++) {
            if(st.find(i) == st.end()) 
                dp[i % 30] = dp[(i-1) % 30];
            else 
                dp[i % 30] = min({ dp[(i-1) % 30] + costs[0], dp[max(0, i-7) % 30] 
                             + costs[1], dp[max(0, i-30) % 30] + costs[2] });
        }
        
        return dp[days.back() % 30];
    }
};