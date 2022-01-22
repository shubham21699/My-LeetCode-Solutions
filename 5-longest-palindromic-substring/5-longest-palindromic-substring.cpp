class Solution {
    bool isPalindrome(string s) {
        
        int i = 0;
        int j = s.length()-1;
        
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        
        return true;
    }
    
public:
    string longestPalindrome(string s) {
        
        int n = s.length();
        
        vector<vector<bool> > dp(n, vector<bool>(n, false));
        int start = 0;
        int maxLen = 1;
        
        for(int i=0 ; i<n ; i++) {
            
            dp[i][i] = true;
            
            for(int j=i-1 ; j>=0 ; j--) {
                
                // i-j == 1 account for palindrome with length 2
                if(s[i] == s[j] && (i-j == 1 || dp[j+1][i-1])) {
                    
                    dp[j][i] = true;
                    int distance = i-j+1;
                    
                    if(maxLen < distance) {
                        maxLen = distance;
                        start = j;
                    }
                    
                }
                
                else dp[j][i] = false;
                
            }
            
        }
        
        return s.substr(start, maxLen);
        
        
//         OR: Will give TLE
//         string result = "";
        
//         for(int i=0 ; i<n ; i++) {
//             for(int j=i ; j<n ; j++) {
//                 string x = s.substr(i, j-i+1);
                
//                 if(isPalindrome(x) && x.length() > result.length()) {
//                     result = x;
//                 }
                
//             }
//         }
        
//         return result;
    }
};