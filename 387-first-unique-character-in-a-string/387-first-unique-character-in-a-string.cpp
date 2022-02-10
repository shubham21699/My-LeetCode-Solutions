class Solution {
public:
    int firstUniqChar(string s) {
        
        int n = s.length();
        if(n == 1) return 0;
        if(n == 2) {
            if(s[0] == s[1]) return -1;
            return 0;
        }
        
        unordered_map<char, int> m;
        for(int i=0 ; i<n ; i++) m[s[i]]++;
        
        for(int i=0 ; i<n ; i++) {
            if(m[s[i]] == 1) return i;
        }
        
        return -1;
    }
};