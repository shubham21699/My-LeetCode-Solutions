class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        
        long long ans = INT_MAX;
        long long low = 1;
        long long high = INT_MAX;
        
        while(low <= high) {
            
            long long mid = low + (high - low)/2;
            
            // Remaining numbers divisible by divisor1 from total mid numbers
            long long total1 = mid - mid/divisor1;
            
            // Remaining numbers divisible by divisor2 from total mid numbers
            long long total2 = mid - mid/divisor2;
            
            // LCM of 2 numbers i.e, divisor1 and divisor2
            long long lcm = ((long long)divisor1 * (long long)divisor2) / __gcd(divisor1, divisor2);
            
            // Remaining numbers not divisible by divisor1 and divisor2 from total mid numbers
            long long total = mid - mid/lcm;
            
            // If we have all satisfied, then set the high value to left of mid and store mid value as ans
            if(total1 >= uniqueCnt1 && total2 >= uniqueCnt2 && total >= uniqueCnt1+uniqueCnt2) {
                ans = min(ans, mid);
                high = mid-1;
            }
            else low = mid+1;
            
        }
        
        return ans;
    }
};