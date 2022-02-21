class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        if(s == t) return true;
        if(n >= m) return false;
        
        for(int i=0 ; i<=m-n ; i++) {
            
            if(t[i] == s[0]) {
                int j = i;
                int k = 0;
                
                while(j<m && k<n) {
                    if(t[j] == s[k]) k++;
                    j++;
                }
                
                if(k == n) return true;
                
            }
            
        }
        
        return false;
    }
};