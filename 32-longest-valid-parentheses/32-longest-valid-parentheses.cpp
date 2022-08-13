class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n = s.length();
        if(n <= 1) return 0;
        if(n == 2) return s == "()" ? 2 : 0;
        
        int open = 0, close = 0;
        int maxLen = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            if(s[i] == '(') open++;
            else close++;
            
            if(open == close) maxLen = max(maxLen, open+close);
            else if(close > open) {
                open = 0;
                close = 0;
            }
            
        }
        
        open = 0;
        close = 0;
        
        for(int i=n-1 ; i>=0 ; i--) {
            
            if(s[i] == '(') open++;
            else close++;
            
            if(open == close) maxLen = max(maxLen, open+close);
            else if(open > close) {
                open = 0;
                close = 0;
            }
            
        }
        
        return maxLen;
        
//         // OR:
//         stack<int> st;
//         st.push(-1);
//         int maxLen = 0;
        
//         for(int i=0 ; i<n ; i++) {
            
//             if(s[i] == '(') st.push(i);
//             else {  
//                 st.pop();
                
//                 if(!st.empty()) maxLen = max(maxLen, i-st.top());
//                 else st.push(i);
//             }
            
//         }
        
//         return maxLen;
    }
};