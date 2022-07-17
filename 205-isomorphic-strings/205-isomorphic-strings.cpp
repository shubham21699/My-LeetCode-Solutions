class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if(s == t) return true;
        
        int n = s.length();
        unordered_map<char, int> ms, mt;
        
        for(int i=0 ; i<n ; i++) {
            
            if(ms.find(s[i]) == ms.end() && mt.find(t[i]) == mt.end()) {
                ms[s[i]] = t[i];
                mt[t[i]] = s[i];
            }
            else if(ms.find(s[i]) == ms.end() || mt.find(t[i]) == mt.end() || ms[s[i]] != t[i] || mt[t[i]] != s[i])
                return false;
            
        }
       
        return true;
        
    }
};