class Solution {
public:
    int countOrders(int n) {
        
        if(n == 1) return 1;
        
        long int result = 1;
        
        for(int i=1 ; i<=n ; i++) {
            // Here, i for factorial and (2*i-1) for series
            result *= (i * (2*i - 1));
            result %= 1000000007;
        }
        
        return result;
    }
};