class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        
        int n = s.length();
        if(n == 1) return true;
        if(s.back() != '0') return false;
        
        // It's a bottom-up DP implementation. The boolean value represents whether this position 
        // is reachable from start. So the first step is to generate the table. Here the table 
        // was pre-labeled True or False, thus '1's are already labeled False.
        // To determine the state of dp[i], one need to check the states in window dp[i-maxJump : i-minJump], 
        // because any one of them can reach i if it's labeled True.
        // Then you need to check if there is a True in this window. As this is a sliding 
        // window problem, so we don't need to calculate it everytime. We only need to remove the 
        // effect from dp[i-maxJump-1] and add the dp[i-minJump]. This is done by these two lines of 
        // code: prevPossPosition += dp[i - minJump] and prevPossPosition -= dp[i - maxJump - 1]
        // The if statements if i >= minJump: and if i > maxJump: are dealing with the initial boundary.
        
        vector<bool> dp(n, false);
        dp[0] = true;
        int prevPossPosition = 0;
        
        for(int i=1 ; i<n ; i++) {

            if(i >= minJump) prevPossPosition += dp[i-minJump];
            if(i > maxJump) prevPossPosition -= dp[i-maxJump-1];
            
            dp[i] = prevPossPosition > 0 && s[i] == '0';
            
        }
        
        return dp[n-1];
    }
};