class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        
        if(denominator == 1) return to_string(numerator);
        if(numerator == 0) return "0";
        
        long n = labs(numerator);
        long d = labs(denominator);
        long r = n % d;
        
        string ans = "";
        if(numerator<0 ^ denominator<0) ans += '-';
        ans += to_string(n / d);
        
        if(r == 0) return ans;
        
        ans += '.';
        unordered_map<long, int> m;
        
        while(r) {
            if(m.find(r) != m.end()) {
                ans.insert(m[r], "(");
                ans += ')';
                break;
            }
            
            m[r] = ans.length();
            r *= 10;
            ans += to_string(r / d);
            r %= d;
        }
        
        return ans;;
    }
};