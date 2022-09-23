class Solution {
public:
    long long mod = pow(10, 9) + 7;
    
    int concatenatedBinary(int n) {
        
        /*
        num = 0;
        n = 2;
        i -> 1 to 2;
        For i = 1,
        (num<<1)^i -> (0<<1)^1 -> (00)^01 -> 01
        num = 01

        next,
        For i = 2,
        (num<<2)^i -> (01<<2)^2 -> (0100)^10 -> 0110
        num = 110 -> 6
        so 6 will be the answer in this way */
        
        long long num = 0;
        
        for(int i=1 ; i<=n ; i++) {
            
            int countBits = log2(i) + 1;
            
            num = ((num<<countBits) ^ i) % mod;
            
        }
        
        return num;
    }
};