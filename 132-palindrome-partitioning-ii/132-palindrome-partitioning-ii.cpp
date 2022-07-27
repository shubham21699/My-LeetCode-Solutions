class Solution {
public:
    bool isPalindrome(string& s) {
        
        int i = 0;
        int j = s.length()-1;
        
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        
        return true;
    }
    
    int count(string& s, int index, int n, vector<int>& dp) {
        
        if(index >= n) return 0;
        if(dp[index] != -1) return dp[index];
        
        int mini = INT_MAX;
        int i;
        int cuts;
        for(i=index ; i<n ; i++) {
            string x = s.substr(index, i-index+1);
            
            if(isPalindrome(x)) {
                cuts = 1 + count(s, i+1, n, dp);
                mini = min(mini, cuts);
            }
            
        }
        
        return dp[index] = mini;
    }
    
    int minCut(string s) {
        
        int n = s.length();
        if(n == 1) return 0;
        if(n == 2) return s[0] == s[1] ? 0 : 1;
        if(isPalindrome(s)) return 0;
        
        // One typical solution is DP based. Such solution first constructs a two-dimensional bool array 
        // isPalin to indicate whether the sub-string s[i..j] is palindrome. To get such array, we need 
        // O(N^2) time complexity. Moreover, to get the minimum cuts, we need another array minCuts to do 
        // DP and minCuts[i] saves the minimum cuts found for the sub-string s[0..i-1]. minCuts[i] is 
        // initialized to i-1, which is the maximum cuts needed (cuts the string into one-letter characters) 
        // and minCuts[0] initially sets to -1, which is needed in the case that s[0..i-1] is a palindrome. 
        // When we construct isPalin array, we update minCuts everytime we found a palindrome sub-string, 
        // i.e. if s[i..j] is a palindrome, then minCuts[j+1] will be updated to the minimum of the current 
        // minCuts[j+1] and minCut[i]+1(i.e. cut s[0..j] into s[0,i-1] and s[i,j]). At last, we return 
        // minCuts[N].
        // So the complexity is O(N^2). However, it can be further improved since as described above, we only 
        // update minCuts when we find a palindrome substring, while the DP algorithm spends lots of time to 
        // calculate isPalin, most of which is false (i.e. not a palindrome substring). If we can reduce such 
        // unnecessary calculation, then we can speed up the algorithm. This can be achieved with a 
        // **Manancher-like solution**, which is also given as following.
        
        vector<vector<bool>> isPalin(n, vector<bool>(n));
        vector<int> minCuts(n+1);
        
        for(int i=0 ; i<=n ; i++) minCuts[i] = i-1;
        
        for(int j=1 ; j<n ; j++) {
            for(int i=j ; i>=0 ; i--) {
                if(s[i] == s[j] && (j-i < 2 || isPalin[i+1][j-1])) {
                    isPalin[i][j] = true;
                    minCuts[j+1] = min(minCuts[j+1], 1 + minCuts[i]);
                }
            }
        }
        
        return minCuts[n];
        
        
        // // OR: Will give TLE
        // vector<int> dp(n, -1);
        // return count(s, 0, n, dp) - 1;
    }
};