class Solution {
public:
    int minOperations(int n) {
        
        if(n == 1) return 1;
        if(ceil(log2(n)) == floor(log2(n))) return 1;
        
        /*
        Intuition :-
            Take a look at the binary of n:
            If there is an alone 1, like ..00001, it takes at leat one operation to remove 
            and we can remove it in one operation.
            So we do result++ and n >>= 1, remove two last bits.
            
            If there are multiple 1s, like ..0000111, we can't remove them in one single operation,
            so it takes at least two operation to remove,
            For example of ..0000111 we can add 1 and then remove 1000.
            So we do n++ and remove the last bit 0.
        
        Explanation :-
            By this stratagy in intuition, we only need to take care of the the continuous 1 in binary of n.
            If it's single 1, result += 1
            If it's multiple 1s, result += 2
        */

        
        int result = 0;
        
        while(n > 0) {
            
            if((n & 3) == 3) {
                result++;
                n++;
            }
            else {
                result += (n & 1);
                n /= 2;
            }
            
        }
        
        return result;
    }
};