class Solution {
public:
    int numSplits(string s) {
        
        int n = s.length();
        unordered_map<char, int> m;
        unordered_set<char> s1;
        
        for(int i=0 ; i<n ; i++) {
            m[s[i]]++;
            s1.insert(s[i]);
        }
        
        int count = 0;
        unordered_set<char> s2;
        
        for(int i=0 ; i<n ; i++) {
            m[s[i]] == 1 ? s1.erase(s[i]) : m[s[i]]--;
            s2.insert(s[i]);
            
            if(s1.size() == s2.size()) count++;
        }
        
        return count;
    }
};