class Solution {
public:
    string finalString(string s) {
        
        int n = s.length();
        string res = "";
        
        for(int i=0 ; i<n ; i++) {
            if(s[i] == 'i') reverse(res.begin(), res.end());
            else res += s[i];
        }
        
        return res;
    }
};