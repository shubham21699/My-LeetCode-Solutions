class Solution {
public:
    int calculate(string s) {
        
        int n = s.length();
        if(n == 1) return s[0]-'0';
        if(n == 2) return stoi(s);
        
        int result = 0;
        int temp = 0;
        int i = 0;
        char op = '+';
        
        while(i < n) {
            
            if(isdigit(s[i])) {
                int num = 0;
                
                while(i<n && isdigit(s[i])) {
                    num = num*10 + (s[i]-'0');
                    i++;
                }
                
                if(op == '+' || op == '-') {
                    result += temp;
                    temp = num * (op == '-' ? -1 : 1);
                }
                else if(op == '*') {
                    temp *= num;
                }
                else if(op == '/') {
                    temp /= num;
                }
                
                continue;
            }
            // If current character is an operator.
            else if(s[i] != ' ') op = s[i];
            
            i++;
        }
        
        result += temp;
        return result;
    }
};