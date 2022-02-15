class Solution {
public:
    int trailingZeroes(int n) {
        
        if(n <= 4) return 0;
        
        int count = 0;
        // Check for multiples of 5 lies till given number 'n'
        // Like mutiples of 5, 5x5, 5x5x5, ... in 'n!'
        // because no. of mutiples of 5 = no. of trailing zeroes will be there in n!.
        for(int i=5 ; i<=n ; i*=5) {
            count += (n/i);
        }
        
        return count;
    }
};