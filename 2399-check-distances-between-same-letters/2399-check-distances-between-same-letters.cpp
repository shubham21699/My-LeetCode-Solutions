class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        
        int n = s.length();
        int m = distance.size();
        
        unordered_map<char, int> mp;
        
        for(int i=0 ; i<n ; i++) {
            
            if(mp.find(s[i]) != mp.end()) continue;
            
            for(int j=i+1 ; j<n ; j++) {
                if(s[i] == s[j]) {
                    mp[s[i]] = j-i-1;
                    break;
                }
            }
        }
        
        for(int i=0 ; i<m ; i++) {
            char c = 'a'+i;
            if(mp.find(c) != mp.end() && mp[c] != distance[i]) return false;
        }
        
        return true;
    }
};