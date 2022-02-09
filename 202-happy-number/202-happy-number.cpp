class Solution {
public:
    bool isHappy(int n) {
        
        if(n == 1) return true;
        unordered_map<int, int> m;
        
        while(n != 1) {
            
            // If this number already comes before, then this exists in loop so return false.
            if(m[n] > 0) return false;
            else m[n]++;
            
            int x = 0;
            while(n) {
                x += (n%10)*(n%10);
                n /= 10;
            }
            n = x;
        }
        
        return true;
    }
};