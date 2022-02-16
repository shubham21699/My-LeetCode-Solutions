class Solution {
public:
    int getSum(int a, int b) {
        
        if(a == 0) return b;
        if(b == 0) return a;
        
        int sum = a;
        uint32_t carry = b;
        
        while(carry != 0) {
            sum = a ^ carry; // Calculate sum of a and b without thinking of carry
            carry = (a & carry) << 1; // Calculate carry
            a = sum; // add sum(one without carry) with the carry
        }
        
        return sum;
    }
};