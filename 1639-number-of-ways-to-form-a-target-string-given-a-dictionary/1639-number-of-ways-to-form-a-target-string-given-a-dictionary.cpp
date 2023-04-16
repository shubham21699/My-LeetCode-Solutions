class Solution {
public:
    int mod = pow(10, 9) + 7;
    
    int ways(vector<string>& words, string& target, int s, int t, int n, int m, int k, unordered_map<int, unordered_map<char, int>>& mp, vector<vector<int>>& dp) {
        
        if(t == k) return 1;
        if(s == m) return 0;
        if(dp[s][t] != -1) return dp[s][t];
        
        int count = ways(words, target, s+1, t, n, m, k, mp, dp);
        
        if(mp[s].find(target[t]) != mp[s].end()) 
            count = (count + (long long) mp[s][target[t]] * ways(words, target, s+1, t+1, n, m, k, mp, dp)) % mod;
        
        return dp[s][t] = count;
    }
    
    int numWays(vector<string>& words, string target) {
        
        int n = words.size();
        int m = words[0].length();
        int k = target.length();
        
        unordered_map<int, unordered_map<char, int>> mp;
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                mp[j][words[i][j]]++;
            }
        }
        
        vector<vector<int>> dp(m+1, vector<int>(k+1, -1));
        
        return ways(words, target, 0, 0, n, m, k, mp, dp);
    }
};