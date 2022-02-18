class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n = num.length();
        if(n == 0 || n == k) return "0";
        
        // Using Monotonic Stack Approach:
        stack<char> s;
        
        for(int i=0 ; i<n ; i++) {
            
            while(!s.empty() && k>0 && s.top() > num[i]) {
                s.pop();
                k--;
            }
            
            if(!s.empty() || num[i] != '0') s.push(num[i]);
            
        }
        
        while(!s.empty() && k>0) {
            s.pop();
            k--;
        }
        
        if(s.empty()) return "0";
        
        while(!s.empty()) {
            num[n-1] = s.top();
            s.pop();
            n--;
        }
        
        return num.substr(n);
    }
};