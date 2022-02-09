class Solution {
public:
    int mySqrt(int x) {
        
        if(x <= 1) return x;
        
        int low = 1;
        int high = x;
        int ans;
        
        while(low <= high) {
            
            long long int mid = low + (high - low)/2;
            
            if(mid*mid == x) return mid;
            else if(mid*mid > x) high = mid-1;
            else {
                low = mid+1;
                ans = mid;
            }
            
        }
        
        return ans;
        
        // OR:
        // if(x <= 1) return x;
        // return floor(sqrt(x));
    }
};