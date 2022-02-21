class Solution {
public:
    bool divisorGame(int n) {
        
        // Let's consider dynomic approach to solve this problem. Let dp[i] be true if Alice wins and 
        // false for the opposite case. Each i such that 1 <= i <= N is either winning or losing 
        // position for Alice. It's easy to see that if 0 < x < i such that i % x == 0 and if 
        // position i - x is winning position for Alice i.e. dp[i - x] == true, then she can 
        // just subtract x from i and move to winning position, therefore for her i is also 
        // winning position. Now it's only left to consider all possible cases where 
        // Alice can win and return dp[N].
        
        vector<bool> dp(n+1, false);
        
        for(int i=2 ; i<=n ; i++) {
            for(int j=1 ; j*j<=i ; j++) {
                if(i%j == 0 && !dp[i-j]) {
                    dp[i] = true;
                }
            }
        }
        
        return dp[n];
        
        
        // OR:
        // return n%2==0;
        
//         If N is even, can win.
//         If N is odd, will lose.

//         Recursive Prove （Top-down)

//         1. If N is even.
//         We can choose x = 1.
//         The opponent will get N - 1, which is a odd.
//         Reduce to the case odd and he will lose.

//         2. If N is odd,
//          2.1 If N = 1, lose directly.
//          2.2 We have to choose an odd x.
//         The opponent will get N - x, which is a even.
//         Reduce to the case even and he will win.

//         3. So the N will change odd and even alternatively until N = 1.

//         Mathematical Induction Prove （Bottom-up)

//         1. N = 1, lose directly
//         2. N = 2, will win choosing x = 1.
//         3. N = 3, must lose choosing x = 1.
//         4. N = 4, will win choosing x = 1.
//         ....

//         For N <= n, we have find that:
//         If N is even, can win.
//         If N is odd, will lose.

//         For the case N = n + 1
//         If N is even, we can win choosing x = 1,
//         give the opponent an odd number N - 1 = n,
//         force him to lose,
//         because we have found that all odd N <= n will lose.

//         If N is odd, there is no even x that N % x == 0.
//         As a result, we give the opponent a even number N - x,
//         and the opponent can win,
//         because we have found that all even N <= n can win.

//         Now we prove that, for all N <= n,
//         If N is even, can win.
//         If N is odd, will lose.
        
    }
};