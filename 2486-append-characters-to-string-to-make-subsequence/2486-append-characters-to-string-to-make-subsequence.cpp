class Solution {
public:
    int appendCharacters(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        int j = 0;
        
        for(int i=0 ; i<n ; i++) {
            if(s[i] == t[j]) j++;
        }
        
        return m-j;
    }
};