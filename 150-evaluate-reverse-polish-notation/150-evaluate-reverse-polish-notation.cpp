class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        int n = tokens.size();
        stack<int> s;
        
        for(int i=0 ; i<n ; i++) {
            
            if(tokens[i] == "+") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                a = a+b;
                s.push(a);
            }
            else if(tokens[i] == "-") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                a = b-a;
                s.push(a);
            }
            else if(tokens[i] == "*") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                a = a*b;
                s.push(a);
            }
            else if(tokens[i] == "/") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                a = b/a;
                s.push(a);
            }
            else s.push(stoi(tokens[i]));
            
        }
        
        return s.top();
    }
};