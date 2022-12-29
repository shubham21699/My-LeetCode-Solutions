 class Solution {
public:
    int MaxNumOfNonOverlappingPS(string& s, int i, int n, int k, vector<vector<bool>>& isPalindrome, vector<int>& dp) {
        
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        
        int ans = 0;
        
        for(int j=i ; j<n ; j++) {
            ans = max(ans, (isPalindrome[i][j] && j-i+1 >= k) + MaxNumOfNonOverlappingPS(s, j+1, n, k, isPalindrome, dp));
        }
        
        return dp[i] = ans;
    }
    
    int maxPalindromes(string s, int k) {
        
        int n = s.length();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        
        for(int gap=0 ; gap<n ; gap++) { // For each gap between i & j
            for(int i=0, j=gap ; j<n ; i++, j++) {
                
                // If gap is 0 then only one char is there and it is palindome.
                if(gap == 0) isPalindrome[i][j] = true;
                
                // If gap is 1, then if both characters are equal then it is a palindrome.
                else if(gap == 1) {
                    if(s[i] == s[j]) isPalindrome[i][j] = true;
                }
                
                // If gap > 1, then if s[i] and s[j] are equal and also there inner substring is also palindrome
                // then it is also palindrome.
                else {
                    if(s[i] == s[j] && isPalindrome[i+1][j-1]) isPalindrome[i][j] = true;
                }
                
            }
        }
        
        vector<int> dp(n+1, -1);
        return MaxNumOfNonOverlappingPS(s, 0, n, k, isPalindrome, dp);
    }
};