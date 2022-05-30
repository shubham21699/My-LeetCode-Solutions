class Solution {
public:
    int divide(int dividend, int divisor) {
        
//         if(dividend == 0) return 0;
//         if(dividend == INT_MAX && divisor == -1) return INT_MIN;
//         if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        
//         int sign = (dividend<0 ^ divisor<0) ? -1 : 1;
        
//         // ans = a/b
//         // Taking log both sides:
//         // log(ans) = log(a/b)
//         // log(ans) = log(a) - log(b)
//         // Taking left side log to right side:
//         // ans = e^(log(a) - log(b))
        
//         long d1 = labs(dividend);
//         long d2 = labs(divisor);
//         long result = exp(log(d1) - log(d2));

//         if(result > INT_MAX) return sign==1 ? INT_MAX : INT_MIN;
//         return sign*(int)result;

        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        
        while (dvd >= dvs) {
            long temp = dvs, m = 1;
            
            while (temp << 1 <= dvd) {
                temp <<= 1;
                m <<= 1;
            }
            
            dvd -= temp;
            ans += m;
        }
        return sign * ans;
    }
};