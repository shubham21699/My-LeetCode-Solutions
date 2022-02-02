class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n = s.length();
        if(n == 0) return 0;
        
        stack<int> st;
        st.push(-1);
        int result = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            if(s[i] == ')') {
                st.pop();
                
                if(!st.empty()) result = max(result, i - st.top());
                else st.push(i);
            }
            else st.push(i);
            
        }
        
        return result;
    }
};