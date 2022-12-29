class Solution {
public:
    /*
    Intuition :-
    The goal is to find the number of palindromic subsequences having length 5, which is a constant.
    It limits the number of combinations, and reduce the complexity to enumerate them.
    
    Approach :-
    We can break down the problem into:
    For each index i, finding the number of palindromic subsequences whose center is s[i].
    The palindrome would be like: [k, j, s[i], j, k], where j and k are digits.
    Since there is only 10 different digits, the number of combinations of the palindrome is 10x10 = 100.
    
    If we can get the number of subsequence [k, j] on the left side of i, and [j, k] on the right side of i, 
    then we get the number of palindromic subsequences whose center is s[i].
    
    So I pre-compute the following two lists, which can be done in O(n.100):
        dp_prefix[i][j][k]: the number of subsequence [j, k] on the left side of i.
        dp_suffix[i][j][k]: the number of subsequence [j, k] on the right side of i.
    and in my code I used dp_prefix[i][j][10] to store the number of j appear on the left side of i, 
    which is useful to compute dp_prefix[i][j][k], same as dp_suffix.
    
    Finally, we iterate all center i to sum up the final answer. */
    
    int mod = pow(10, 9) + 7;
    long long dp_prefix[10001][10][11];
    long long dp_suffix[10001][10][11];
    
    int countPalindromes(string s) {
        
        int n = s.length();
        if(n < 5) return 0;
        
        // Pre-compute dp_prefix from left to right
        for(int i=1 ; i<n ; i++) {
            for(int j=0 ; j<10 ; j++) {
                for(int k=0 ; k<10 ; k++) {
                    dp_prefix[i][j][k] = dp_prefix[i-1][j][k];
                }
            }
            
            for(int j=0 ; j<10 ; j++) dp_prefix[i][j][s[i-1]-'0'] += dp_prefix[i-1][j][10];
            for(int j=0 ; j<10 ; j++) dp_prefix[i][j][10] = dp_prefix[i-1][j][10];
            dp_prefix[i][s[i-1]-'0'][10]++;
        }
        
        // Pre-compute dp_suffix from right to left
        for(int i=n-2 ; i>=0 ; i--) {
            for(int j=0 ; j<10 ; j++) {
                for(int k=0 ; k<10 ; k++) {
                    dp_suffix[i][j][k] = dp_suffix[i+1][j][k];
                }
            }
            
            for(int j=0 ; j<10 ; j++) dp_suffix[i][s[i+1]-'0'][j] += dp_suffix[i+1][j][10];
            for(int j=0 ; j<10 ; j++) dp_suffix[i][j][10] = dp_suffix[i+1][j][10];
            dp_suffix[i][s[i+1]-'0'][10]++;
        }
        
        // Compute final answer
        int countPS = 0;
        
        for(int i=2 ; i<n-2 ; i++) {
            for(int j=0 ; j<10 ; j++) {
                for(int k=0 ; k<10 ; k++) {
                    countPS = (countPS + (dp_prefix[i][j][k] * dp_suffix[i][k][j]) % mod) % mod;
                }
            }
        }
        
        return countPS;
    }
};