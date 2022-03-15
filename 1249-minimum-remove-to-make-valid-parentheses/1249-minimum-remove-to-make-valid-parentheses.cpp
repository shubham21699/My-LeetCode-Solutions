class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int n = s.length();
        if(n == 0) return "";
        stack<int> st;
        
        for(int i=0 ; i<n ; i++) {
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')') {
                if(!st.empty()) st.pop();
                else s[i] = '#'; // Invalid parantheses position.
            }
        }
        
        // All the indexes left in stack are invalid.
        while(!st.empty()) {
            s[st.top()] = '#';
            st.pop();
        }
        
        // Removing all the '#' from invalids parantheses position.
        s.erase(remove(s.begin(), s.end(), '#'), s.end());
        return s;
    }
};