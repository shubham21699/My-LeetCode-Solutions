class Solution {
public:
    string simplifyPath(string path) {
        
        int n = path.length();
        if(n == 0) return "";
        if(n == 1) return path;
        
        string result = "";
        result += path[0];
        stack<string> st;
        int i = 1;
        
        while(i < n) {
            
            string s = "";
            while(i<n && path[i] != '/') {
                s += path[i];
                i++;
            }
            
            if(s == "..") {
                if(!st.empty()) st.pop();
                else continue;
            }
            else if(s == ".") continue;
            else if(s.length() >= 1) st.push(s);
            
            if(path[i] == '/') i++;
        }
        
        stack<string> st2;
        while(!st.empty()) {
            st2.push(st.top());
            st.pop();
        }
        
        while(!st2.empty()) {
            result += st2.top();
            st2.pop();
            result += '/';
        }
        
        if(result.size() > 1 && result.back() == '/') result.pop_back();
        return result;
    }
};