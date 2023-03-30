class Solution {
public:    
    bool scramble(unordered_map<string, int>& dp, string s, string t) {
        
        int n = s.length();
        int m = t.length();
        if(n == 0) return true;
        if(s == t) return true;
        if(dp.find(s+t) != dp.end()) return dp[s+t];
        
        bool result = false;
        
        for(int i=1 ; i<n ; i++) {
            result |= scramble(dp, s.substr(0, i), t.substr(0, i)) && scramble(dp, s.substr(i), t.substr(i));
            
            result |= scramble(dp, s.substr(0, i), t.substr(n-i)) && scramble(dp, s.substr(i), t.substr(0, n-i));
        }
        
        return dp[s+t] = result;
        
    }
    
    bool isScramble(string s1, string s2) {
        
        int n = s1.length();
        int m = s2.length();
        if(s1 == s2) return true;
        
        unordered_map<string, int> dp;
        return scramble(dp, s1, s2);
    }
};