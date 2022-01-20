class Solution {
//     bool isPalindrome(string s) {
        
//         int i = 0;
//         int j = s.length();
        
//         while(i < j) {
//             if(s[i] != s[j]) return false;
//             i++;
//             j--;
//         }
        
//         return true;
//     }
    
//     int find(string s, int i, int j, vector<vector<int> >& dp) {
        
//         if(i > j) return 0;
//         if(i == j) return 1;
//         if(dp[i][j] != 0) return dp[i][j];
        
//         if(s[i] == s[j]) dp[i][j] = find(s, i+1, j-1, dp) + 2;
//         else dp[i][j] = max(find(s, i+1, j, dp), find(s, i, j-1, dp));
        
//         return dp[i][j];
//     }
    
public:
    int memo[1000][1000] = {};
    int longestPalindromeSubseq(string s) {
        return dp(s, 0, s.size() - 1);
    }
    int dp(const string& s, int l, int r) {
        if (l > r) return 0; // Return 0 since it's empty string
        if (l == r) return 1; // Return 1 since it has 1 character
        if (memo[l][r] != 0) return memo[l][r];
        if (s[l] == s[r])
            return memo[l][r] = dp(s, l+1, r-1) + 2;
        return memo[l][r] = max(dp(s, l+1, r), dp(s, l, r-1));
    }
//     int longestPalindromeSubseq(string s) {
        
//         int n = s.length();
        
//         if(n == 1) return 1;
//         if(n == 2) {
//             if(s[0] == s[1]) return 2;
//             return 1;
//         }
        
//         if(isPalindrome(s)) return n;
        
//         vector<vector<int> > dp(n, vector<int>(n, 0));
//         return find(s, 0, n-1, dp);
        
//     }
};