class Solution {
public:
    int calculate(string s) {
        
        int n = s.length();
        stack<int> st;
        int num = 0;
        int sign = 1;
        int result = 0;
        int i = 0;
        
        while(i < n) {
            
            if(isdigit(s[i])) {
                num = s[i] - '0';
                
                while(i+1<n && isdigit(s[i+1])) {
                    num = num*10 + (s[i+1] - '0');
                    i++;
                }
                
                result += sign * num;
            }
            else if(s[i] == '+' || s[i] == '-') {
                sign = s[i] == '+' ? 1 : -1;
            }
            else if(s[i] == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            }
            else if(s[i] == ')') {
                int stSign = st.top();
                st.pop();
                result = stSign*result + st.top();
                st.pop();
            }
            
            i++;
        }
        
        return result;
    }
};