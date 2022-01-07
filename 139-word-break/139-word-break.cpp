class Solution {
    bool find(string s, unordered_set<string> st, int startInd, int index, int n, vector<bool>& dp) {
        
        string ch = s.substr(startInd, index-startInd+1);
        
        if(index >= n) return false;
        if(index == n-1 && st.find(ch) != st.end()) return true;
        if(dp[index]) return dp[index];
        
        if(st.find(ch) != st.end()) {
            dp[index] = find(s, st, startInd, index+1, n, dp) || find(s, st, index+1, index+1, n, dp);
        }
        else dp[index] = find(s, st, startInd, index+1, n, dp);
        
        return dp[index];
    } 
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.length();
        int m = wordDict.size();
        
        unordered_set<string> st;
        vector<bool> dp(n+1, false);
        dp[0] = true;
        
        for(int i=0 ; i<m ; i++) st.insert(wordDict[i]);
        
        // Giving TLE:
        // return find(s, st, 0, 0, n, dp);
        
        for(int i=1 ; i<=n ; i++) {
            for(int j=i-1 ; j>=0 ; j--) {
                if(dp[j] == true) {
                    string ch = s.substr(j, i-j);
                    
                    if(st.find(ch) != st.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        return dp[n];
        
    }
};