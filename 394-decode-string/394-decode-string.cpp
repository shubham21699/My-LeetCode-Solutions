class Solution {
public:
    string decodeString(string s) {
        
        int n = s.length();
        stack<string> st;
        
        for(int i=0 ; i<n ; i++) {
            
            if(s[i] == ']') {
                
                // 1st get the string to be encode.
                string x = "";
                while(!st.empty() && st.top() != "[") {
                    reverse(st.top().begin(), st.top().end());
                    x += st.top();
                    st.pop();
                }
                st.pop();
                reverse(x.begin(), x.end());
                
                // Then get the number to which how much times it to be repeated.
                string num = "";
                while(!st.empty() && st.top() >= "0" && st.top() <= "9") {
                    num += st.top();
                    st.pop();
                }
                reverse(num.begin(), num.end());
                int k = stoi(num);
                
                // Then encode the string k times.
                string y = "";
                while(k--) {
                    y += x;
                }
                
                // Then push the encoded string back to stack according to available string s.
                if(!st.empty() && st.top() != "[") st.top() += y;
                else st.push(y);
                
            }
            
            else {
                string ch = "";
                st.push(ch + s[i]);
            }
            
        }
        
        // Now get the resultant string to be returned from the stack. 
        string result = "";
        while(!st.empty()) {
            reverse(st.top().begin(), st.top().end());
            result += st.top();
            st.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};