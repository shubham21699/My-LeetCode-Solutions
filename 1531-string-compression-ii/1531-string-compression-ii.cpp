class Solution {
public:
    // Length of digit
    int digitLen(int x) {
        return x == 1 ? 0 : x < 10 ? 1 : x < 100 ? 2 : 3;
    }
    
    int compressedLen(string s, int leftInd, int n, int k, vector<vector<int>>& dp) {
        
        if(k < 0) return 1e9; // Invalid
        if(leftInd >= n || n-leftInd <= k) return 0; // Empty
        if(dp[leftInd][k] != -1) return dp[leftInd][k];
        
        int res = 1e9;
        vector<int> count(26, 0);
        
        // We try to make s[leftInd:j] (both inculded) as one group and all chars in this group should be the same.
        // So we must keep the most chars in this range and remove others. The range length is (j - leftInd + 1)
        // and the number of chars we need to remove is (j - leftInd + 1 - most)
        
        for(int j=leftInd, most=0 ; j<n ; j++) {
            count[s[j]-'a']++;
            most = max(most, count[s[j]-'a']); // most = max(count[s[leftInd:j]]);
            res = min(res, 1 + digitLen(most) + compressedLen(s, j+1, n, k - (j-leftInd+1-most), dp));
        }
        
        return dp[leftInd][k] = res;
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        
        int n = s.length();
        
        // dp[leftInd][k] means the minimal coding size for substring s[leftInd:] and removing at most k chars
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        
        return compressedLen(s, 0, n, k, dp);
    }
};