class Solution {
public:
    int partitionString(string s) {
        
        int n = s.length();
        int count = 0;
        unordered_set<char> st;
        
        for(int i=0 ; i<n ; i++) {
            if(st.find(s[i]) != st.end()) {
                st.clear();
                count++;
            }
            
            st.insert(s[i]);
        }
        
        return count+1;
    }
};