class Solution {
public:
    int minimizeXor(int num1, int num2) {
        
        int num2setbits = 0;
        int n = num2;
        
        while(n) {
            if(n & 1) num2setbits++;
            n /= 2;
        }
        
        int result = 0;
        
        // xor of 1 and 1 is 0, so minimizing num1 by setting bits in result
        for(int i=31 ; i>=0 ; i--) {
            if(num1 & (1<<i)) {
                result ^= (1<<i);
                num2setbits--;
                if(num2setbits == 0) break;
            }
        }
        
        // number of bits in result should be same as num2, so setting in result the unset bits of num1
        if(num2setbits > 0) {
            for(int i=0 ; i<32 ; i++) {
                if((num1 & (1<<i)) == 0) {
                    result ^= (1<<i);
                    num2setbits--;
                    if(num2setbits == 0) break;
                }
            }
        }
        
        return result;
    }
};