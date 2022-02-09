class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int count = 0; // Count of set bit.
        
        // Iterate untill all the bits are traversed.
        while(n) {
            
            // Check the parity of 1st bit from right, If it is 1 then increase the count.
            if(n&1 == 1) count++;
            n >>= 1; // Shift one bit to right by n = n/2;
            
        }
        
        return count;
    }
};