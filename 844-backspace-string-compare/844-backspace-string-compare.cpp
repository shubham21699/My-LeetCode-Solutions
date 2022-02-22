class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        if(s == t) return true;
        
        string rs, rt;
        
        for(int i=0 ; i<n ; i++) {
            if(s[i] == '#') {
                if(!rs.empty()) rs.pop_back();
                else continue;
            }
            else rs += s[i];
        }
        
        for(int j=0 ; j<m ; j++) {
            if(t[j] == '#') {
                if(!rt.empty()) rt.pop_back();
                else continue;
            }
            else rt += t[j];
        }
        
        if(rs == rt) return true;
        return false;
    }
};