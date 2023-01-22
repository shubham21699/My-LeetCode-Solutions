class Solution {
public:
    int alternateDigitSum(int n) {
        
        int sign = 1;
        string s = to_string(n);
        int result = 0;
        
        for(int i=0 ; i<s.length() ; i++) {
            result += (s[i]-'0') * sign;
            sign *= -1;
        }
        
        return result;
    }
};