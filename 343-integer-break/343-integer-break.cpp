class Solution {
public:
    int integerBreak(int n) {
        
        if(n <= 2) return 1;
        if(n == 3) return 2;
        if(n == 4) return 4;
        vector<int> dp(n+1, 0);
        
        /*
        2 => 1, 1 => 1
        3 => 2, 1 => 2
        4 => 2, 2 => 4
        5 => 3, 2 => 6
        6 => 3, 3 => 9
        7 => 3, 4 => 12
        8 => 3, 5 => 18
        9 => 3, 6 => 27
        10 => 3, 7 => 36

        By observation, when you get maximum, one of the num is always 3.
        After 3, the result will be larger than or equal the number itself. */
        
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        dp[4] = 4;
        
        for (int i = 5; i <= n; ++i) {
            dp[i] = 3 * max(i - 3, dp[i - 3]);
        }
        
        return dp[n];
        
        
//         // OR:-
//         dp[1] = 1;
//         dp[2] = 1;
        
//         for(int i=3 ; i<=n ; i++) {
//             for(int j=1 ; j<i ; j++) {
//                 /** Try to write i as: i = j + S where S=i-j corresponds to either one number 
//                 or a sum of two or more numbers
                
//                 Assuming that j+S corresponds to the optimal solution for dp[i], we have two cases:
//                 (1) i is the sum of two numbers, i.e. S=i-j is one number, and so dp[i]=j*(i-j)
//                 (2) i is the sum of at least three numbers, i.e. S=i-j is a sum of at least 2 numbers,
//                 and so the product of the numbers in this sum for S is dp[i-j]
//                 (=maximum product after breaking up i-j into a sum of at least two integers):
//                 dp[i] = j*dp[i-j]
//                 */
//                 dp[i] = max({ dp[i], j*(i-j), j*dp[i-j] });
//             }
//         }
        
//         return dp[n];
    }
};