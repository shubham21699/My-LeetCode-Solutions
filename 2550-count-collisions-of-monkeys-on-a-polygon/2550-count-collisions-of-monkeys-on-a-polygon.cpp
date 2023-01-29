class Solution {
public:
    int mod = pow(10, 9) + 7;
    
    int monkeyMove(int n) {
        
        // There will be only 2 ways in which no collision will be possible - when all monkeys move in one
        // direction i.e. either clockwise or anti-clockwise.
        // So, possible ways will be total_ways - 2 i.e. pow(2, n) - 2
        
        int total_ways = 1;
        long long base = 2;
        
        while(n) {
            if(n % 2 == 1) total_ways = (total_ways * base) % mod;
            base = (base * base) % mod;
            n /= 2;
        }
        
        return (total_ways - 2 + mod) % mod;
    } 
};