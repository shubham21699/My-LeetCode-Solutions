class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.length();
        if(n == 1) {
            if(s[0] == ' ') return "";
            return s;
        }
        
        int i = 0;
        while(i < n && s[i] == ' ') i++;
        if(i == n-1) return "";
        
        string result = "";
        stack<string> st;
        
        while(i < n) {
            
            if(s[i] == ' ') {
                i++;
                continue;
            }
            
            string t = "";
            while(i < n && s[i] != ' ') {
                t += s[i];
                i++;
            }
            
            if(!t.empty()) st.push(t);
            
        }
        
        while(!st.empty()) {
            result += st.top();
            st.pop();
            if(!st.empty()) result += " ";
        }
        
        return result;
    }
};