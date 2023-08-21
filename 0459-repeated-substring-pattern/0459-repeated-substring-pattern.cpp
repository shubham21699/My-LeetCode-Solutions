class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        string st = s + s;
        return st.substr(1, st.length() - 2).find(s) != -1;
    }
};