class Solution {
public:
    string removeStars(string s) {
        
        int n = s.length();
        if(n == 1) return s;
        
        string result = "";
        
        for(int i=0 ; i<n ; i++) {
            if(s[i] == '*') result.pop_back();
            else result += s[i];
        }
        
        return result;
    }
};