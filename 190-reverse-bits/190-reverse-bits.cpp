class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t reverse = 0;
        
        for(int i=0 ; i<32 ; i++) {
            
            // Bitwise left shift 'reverse' by 1
            reverse <<= 1;
            
            // If current bit is '1'
            if(n&1 == 1) reverse ^= 1;
            
            // Bitwise right shift 'n' by 1
            n >>= 1;
            
        }
        
        return reverse;
    }
};