class Solution {
public:
    int minimumOneBitOperations(int n) {
        
        /*
        Note that the number of operations for n to become 0 is the same as the number of operations
        for 0 to become n...

        Let's see how it can be done for numbers that are powers of 2.
        1 -> 0 => 1
        10 -> 11 -> 01 -> ... => 2 + 1
        100 -> 101 -> 111 -> 110 -> 010 -> ... => 4 + 2 + 1
        1000 -> 1001 -> 1011 -> 1010 -> 1110 -> 1111 -> 1101 -> 1100 -> 0100 -> ... => 8 + 4 + 2 + 1
        We can find that for 2^n, it needs 2^(n+1) - 1 operations to become 0.

        Now suppose we want to know the number of operations for 1110 to become 0. We know it takes 15 
        operations for 0 to become 1000, and it takes 4 operations for 1000 to become 1110. We get the
        solution by 15 - 4.
        Note that 4 here is the number of operations from 1000 to become 1110, which is the same as the
        number of operations from 000 to 110 (ignoring the most significant bit), and it can be computed
        recursively. The observation gives us: 
        minimumOneBitOperations(1110) + minimumOneBitOperations(0110) = minimumOneBitOperations(1000).

        From the above intuition, we can reduce n bit by bit, starting from the most significant bit.
        */
        
        if(n <= 1) return n;
        
        int bit = 0;
        while ((1 << bit) <= n) {
            bit++;
        }
        
        return ((1 << bit) - 1) - minimumOneBitOperations(n - (1 << (bit-1)));
    }
};