class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        
        int n = words.size();
        
        // dp[mask][i] : min superstring made by strings in mask and last one is words[i];
        vector<vector<string>> dp(1<<n, vector<string>(n));
        vector<vector<int>> overlap(n, vector<int>(n, 0));
        
        // 1. Calculate overlap for words[i]+words[j].substr(?)
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<n ; j++) {
                
                if(i == j) continue;
                
                for(int k=min(words[i].length(), words[j].length()) ; k>0 ; k--) {
                    
                    if(words[i].substr(words[i].length()-k) == words[j].substr(0, k)) {
                        overlap[i][j] = k;
                        break;
                    }
                    
                }
                
            }
        }
        
        // 2. Set Initial value of DP
        for(int i=0 ; i<n ; i++) {
            dp[1<<i][i] += words[i];
        }
        
        // 3. Fill the DP
        for(int mask=1 ; mask<(1<<n) ; mask++) {
            for(int j=0 ; j<n ; j++) {
                
                if((mask & (1<<j)) == 0) continue;
                
                for(int i=0 ; i<n ; i++) {
                    
                    if(i != j && (mask & (1<<i)) > 0) {
                        
                        string temp = dp[mask^(1<<j)][i] + words[j].substr(overlap[i][j]);
                        
                        if(dp[mask][j].empty() || temp.length() < dp[mask][j].length()) {
                            dp[mask][j] = temp;
                        }
                        
                    }
                    
                }
                
            }
        }
        
        // 4. Get Result
        int last = (1<<n)-1;
        string result = dp[last][0];
        
        for(int i=1 ; i<n ; i++) {
            if(dp[last][i].length() < result.length()) {
                result = dp[last][i];
            }
        }
         
        return result;
    }
};