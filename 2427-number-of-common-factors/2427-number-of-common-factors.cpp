class Solution {
public:
    int commonFactors(int a, int b) {
        
        int count = 0;
        int x = 1;
        
        while(x <= gcd(a, b)) {
            if(a % x == 0 && b % x == 0) count++;
            x++;
        }
        
        return count;
    }
};