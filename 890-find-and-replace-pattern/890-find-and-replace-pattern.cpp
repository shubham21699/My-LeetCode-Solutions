class Solution {
public:
    bool check(string s, string t) {
        
        unordered_map<char, char> mp;
        unordered_map<char, bool> visited;
        
        for(int i=0 ; i<s.size() ; i++) {
            
            if(mp.find(s[i]) != mp.end() && mp[s[i]] != t[i]) return false;
            if(mp.find(s[i]) == mp.end() && visited.find(t[i]) != visited.end()) return false;
         
            mp[s[i]] = t[i];
            visited[t[i]] = true;
        }
        
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        int n = words.size();
        int m = pattern.length();
        
        vector<string> res;
        
        for(int i=0 ; i<n ; i++) {
            if(check(words[i], pattern)) res.push_back(words[i]);
        }
        
        return res;
    }
};