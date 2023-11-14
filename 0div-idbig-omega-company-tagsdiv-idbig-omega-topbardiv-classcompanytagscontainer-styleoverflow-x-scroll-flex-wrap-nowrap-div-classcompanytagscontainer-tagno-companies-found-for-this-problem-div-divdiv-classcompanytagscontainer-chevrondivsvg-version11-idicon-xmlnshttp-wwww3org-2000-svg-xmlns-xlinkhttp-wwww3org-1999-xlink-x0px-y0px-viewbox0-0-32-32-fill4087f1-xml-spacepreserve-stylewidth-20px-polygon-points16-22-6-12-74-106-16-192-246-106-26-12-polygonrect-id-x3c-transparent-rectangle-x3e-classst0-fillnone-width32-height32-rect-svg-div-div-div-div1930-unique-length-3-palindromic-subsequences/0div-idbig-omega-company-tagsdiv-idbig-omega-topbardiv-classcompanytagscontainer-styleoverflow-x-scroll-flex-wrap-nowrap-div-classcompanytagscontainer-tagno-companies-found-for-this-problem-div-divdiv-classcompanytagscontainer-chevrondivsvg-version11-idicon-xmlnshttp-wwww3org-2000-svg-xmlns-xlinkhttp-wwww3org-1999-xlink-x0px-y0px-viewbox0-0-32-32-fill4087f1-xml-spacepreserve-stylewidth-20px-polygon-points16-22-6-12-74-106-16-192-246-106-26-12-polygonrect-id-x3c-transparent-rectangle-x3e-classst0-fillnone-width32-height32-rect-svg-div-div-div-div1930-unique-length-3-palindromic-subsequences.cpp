class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        int n = s.length();
        if(n < 3) return 0;
        if(n == 3) return s[0] == s[2] ? 1 : 0;
        
        unordered_map<char, pair<int, int>> mp;
        
        for(int i=0 ; i<n ; i++) {
            if(mp.find(s[i]) == mp.end()) mp[s[i]].first = i;
            else mp[s[i]].second = i;
        }
        
        int count = 0;
        
        for(auto it=mp.begin() ; it!=mp.end() ; it++) {
            
            unordered_set<char> st;
            
            for(int j=it->second.first+1 ; j<it->second.second ; j++) {
                st.insert(s[j]);
            }
            
            count += st.size();
        }
        
        return count;
    }
};