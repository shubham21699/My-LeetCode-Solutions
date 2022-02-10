class Solution {
public:
    int myAtoi(string s) {
        
        int n = s.length();
        int i = 0;
        
        while(s[i] == ' ' && i<n) i++;
        
        int sign = 1;
        if(s[i] == '-') {
            sign = -1;
            i++;
        }
        else if(s[i] == '+') i++;
        
        long long int result = 0;
        
        while(i < n && s[i]>='0' && s[i]<='9') {
            
            result = result*10 + (s[i]-'0');
            
            if(result*sign >= INT_MAX) return INT_MAX;
            if(result*sign <= INT_MIN) return INT_MIN;
            
            i++;
        }
        
        return result*sign;
    }
};