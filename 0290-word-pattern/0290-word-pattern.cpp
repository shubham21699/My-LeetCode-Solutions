class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        int n = pattern.length();
        int m = s.length();
        vector<string> v;
        string x = "";
        
        for(int i=0 ; i<m ; i++) {
            if(s[i] == ' ') continue;
            
            x += s[i];
            
            if(i == m-1 || s[i+1] == ' ') {
                v.push_back(x);
                x = "";
            }
        }
        
        if(n != v.size()) return false;
        
        unordered_map<string, string> mp;
        
        for(int i=0 ; i<n ; i++) {
            string x = to_string(pattern[i]);
            
            if(mp.find(x) != mp.end()) {
                if(mp[x] != v[i]) return false;
            }
            else if(mp.find(v[i]) != mp.end()) {
                if(mp[v[i]] != x) return false;
            }
            else {
                mp[x] = v[i];
                mp[v[i]] = x;
            }
        }
        
        return true;
    }
};