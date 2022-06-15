class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        int n = words.size();
        unordered_map<string, int> dp;
        int result = 0;
        
        sort(words.begin(), words.end(), [](string a, string b) {
            return a.length() < b.length();
        });
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<words[i].length() ; j++) {
                string x = words[i].substr(0, j) + words[i].substr(j+1);
                dp[words[i]] = max(dp[words[i]], dp.find(x)!=dp.end() ? dp[x]+1 : 1);
            }
            
            result = max(result, dp[words[i]]);
        }
        
        return result;
    }
};