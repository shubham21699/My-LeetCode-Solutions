class Solution {
public:
    int hamDist(string s, string t) {
        
        int n = s.length();
        int countDiff = 0;
        
        for(int i=0 ; i<n ; i++) {
            if(s[i] != t[i]) countDiff++;
            if(countDiff > 1) break;
        }
        
        return countDiff;
    }
    
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        
        vector<string> result;
        vector<vector<string>> dp(n);
        int maxSubseqLen = 0;
        
        for(int i=0 ; i<n ; i++) {
            dp[i].push_back(words[i]);
            
            for(int j=0 ; j<i ; j++) {
                if(groups[i] != groups[j] && words[i].length() == words[j].length() && hamDist(words[i], words[j]) == 1) {
                    // Check whether from this index you are getting max length subsequence
                    if(dp[j].size() + 1 > dp[i].size()) {
                        dp[i] = dp[j];
                        dp[i].push_back(words[i]);
                    }
                }
            }
            
            maxSubseqLen = max(maxSubseqLen, int(dp[i].size()));
        }
        
        for(int i=0 ; i<n ; i++) {
            if(dp[i].size() == maxSubseqLen) {
                result = dp[i];
                break;
            }
        }
        
        return result;
    }
};