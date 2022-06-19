class Solution {
public:
    string greatestLetter(string s) {
        
        int n = s.length();
        unordered_map<char, int> mp;
        
        for(int i=0 ; i<n ; i++) {
            mp[s[i]]++;
        }
        
        char x = ' ';
        for(int i=0 ; i<n ; i++) {
            if(isupper(s[i])) {
                char c = tolower(s[i]);
                if(mp.find(c) != mp.end()) {
                    if(x == ' ') x = s[i];
                    else if(s[i] > x) x = s[i];
                }
            }
        }
        
        if(x == ' ') return "";
        
        string res = "";
        return res+x;
    }
};