class Solution {
public:
    char lowPref(map<char, int>& mp) {
        
        for(auto it=mp.begin() ; it!=mp.end() ; it++) {
            if(it->second) return it->first;
        }
        
        return 'a';
    }
    
    string robotWithString(string s) {
        
        int n = s.length();
        map<char, int> mp;
        
        for(int i=0 ; i<n ; i++) mp[s[i]]++;
        
        string result = "";
        stack<char> st;
        
        for(int i=0 ; i<n ; i++) {
            
            while(!st.empty() && st.top() <= lowPref(mp)) {
                result += st.top();
                st.pop();
            }
            
            st.push(s[i]);
            mp[s[i]]--;
        }
        
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        return result;
    }
};