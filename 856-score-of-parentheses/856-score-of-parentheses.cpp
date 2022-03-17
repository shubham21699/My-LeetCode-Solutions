class Solution {
public:
    int scoreOfParentheses(string s) {
        
        int n = s.length();
        if(n == 2) return 1;
        
        stack<int> st;
        st.push(0); // To keep the total score 
        
        for(int i=0 ; i<n ; i++) {
            if(s[i] == '(') st.push(0); // When meets '(', just push a zero to stack
            else {
                int temp = st.top(); // Balance the last '(', it stored the score of inner parentheses
                st.pop();
                int val = 0;
                
                // Not zero means inner parentheses exists and double it
                if(temp > 0) val = temp*2;
                
                // Else xero means no inner parentheses, just using 1
                else val = 1;
                
                st.top() += val; // Pass the score of this level to parent parenthese
            }
        }
        
        return st.top();
    }
};