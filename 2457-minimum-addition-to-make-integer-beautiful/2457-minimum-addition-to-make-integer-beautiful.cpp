class Solution {
public:
    long long digitSum(long long n) {
        
        long long sum = 0;
        
        while(n) {
            sum += n%10;
            n /= 10;
        }
        
        return sum;
    }
    
    long long makeIntegerBeautiful(long long n, int target) {
        
        // Take example of n = 123456, the process is
        // 123456 -> 123460 -> 123500 -> 124000 -> 130000 -> 2000000
        
        long long x = n;
        long long base = 1;
        
        while(digitSum(x) > target) {
            x = x/10 + 1;
            base *= 10;
        }
        
        return x*base - n;
    }
};