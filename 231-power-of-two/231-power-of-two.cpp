class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n <= 0) return false;
        return ((n&(n-1)) == 0);
        
//         OR:
//         if(n == 1 || n == 2) return true;
//         if(n%2 != 0 || n <= 0) return false;
        
//         while(n > 2) {
//             n /= 2;
//             if(n % 2 != 0) return false;
//         }
        
//         return true;
    }
};