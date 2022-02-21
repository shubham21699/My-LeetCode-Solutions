class Solution {
public:
    int fib(int n) {
        
        if(n <= 1) return n;
        
        vector<int> f(n+1, 0);
        f[1] = f[2] = 1;
        
        for(int i=3 ; i<=n ; i++) {
            f[i] = f[i-2] + f[i-1];
        }
        
        return f[n];
        
        // OR:
        // if(n <= 1) return n;
        // return fib(n-2) + fib(n-1);
    }
};