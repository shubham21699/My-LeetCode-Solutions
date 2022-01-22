class Solution {
    int max(int a, int b) {
        if(a > b) return a;
        return b;
    }
    
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        if(n <= 1) return n;
        if(n == 2) {
            if(s[0] == s[1]) return 1;
            return 2;
        }
        
        int maxLen = 1;
        unordered_set<char> st;
        int j = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            if(st.find(s[i]) != st.end()) {
                maxLen = max(maxLen, st.size());
                
                while(st.find(s[i]) != st.end()) {
                    st.erase(s[j]);
                    j++;
                }
                
            }
            
            st.insert(s[i]);
        
        }
        
        maxLen = max(maxLen, st.size());
        return maxLen;
        
    }
};