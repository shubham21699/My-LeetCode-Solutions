class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        int n = s.length();
        if(n == 1) return s;
        if(n == 2) {
            if(k == 2 && s[0] == s[1]) return "";
            return s;
        }
        
        stack<pair<char, int>> st;
        
        for(int i=0 ; i<n ; i++) {
            
            if(st.empty() || st.top().first != s[i]) st.push({ s[i], 1 });
            else {
                auto p = st.top();
                st.pop();
                if(p.second+1 == k) continue;
                else st.push({ p.first, p.second+1 });
            }
            
        }
        
        string result = "";
        
        while(!st.empty()) {
            
            auto p = st.top();
            st.pop();
            
            while(p.second > 0) {
                result += p.first;
                p.second--;
            }
            
        }
        
        reverse(result.begin(), result.end());
        return result;
        
        
//         // OR: Will give TLE
//         stack<string> st;
        
//         for(int i=0 ; i<n ; i++) {
            
//             string x = st.empty() ? "" : st.top();
//             if(!st.empty()) st.pop();
//             x += s[i];
//             st.push(x);
            
//             if(i >= k-1) {
                
//                 string z = st.top();
//                 int count = 0;
                
//                 while(z.back() == s[i] && count < k) {
//                     count++;
//                     z.pop_back();
//                 }
                
//                 if(count == k) {
//                     st.pop();
//                     st.push(z);
//                 }
                
//             }
            
//         }
        
//         return st.top();
    }
};