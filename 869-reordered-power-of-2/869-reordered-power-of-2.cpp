class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        if(n == 1) return true;
        if(n < 10 && (n&(n-1)) == 0) return true;
        if(n <= 10) return false;
        if((n&(n-1)) == 0) return true;
        
        string powerOf2 = to_string(n);
        sort(powerOf2.begin(), powerOf2.end());
        
        for(int i=0 ; i<32 ; i++) {
            int x = 1 << i; // Check for every power of 2
            string check = to_string(x);
            sort(check.begin(), check.end());
            
            if(powerOf2 == check) return true;
        }
        
        return false;
    }
};