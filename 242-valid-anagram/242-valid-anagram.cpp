class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        if(n != m) return false;
        
        unordered_map<char, int> mp;
        
        for(int i=0 ; i<n ; i++) {
            mp[s[i]]++;
            mp[t[i]]--;
        }
        
        for(auto it=mp.begin() ; it!=mp.end() ; it++) {
            if(it->second) return false;
        }
        
        return true;
        
//         OR: Space Efficient but O(nLogn)
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
        
//         if(s == t) return true;
//         return false;
    }
};