class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        
        int n = gcd(targetX, targetY);
        
        while(n % 2 == 0) {
            n /= 2;
        }
        
        return n == 1;
    }
};