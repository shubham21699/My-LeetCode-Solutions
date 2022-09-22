class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.length();
        string result = "";
        string x = "";
        
        for(int i=0 ; i<n ; i++) {
            if(s[i] == ' ' && !x.empty()) {
                reverse(x.begin(), x.end());
                result += x + " ";
                x = "";
            }
            else x += s[i];
        }
        
        reverse(x.begin(), x.end());
        result += x;
        return result;
    }
};