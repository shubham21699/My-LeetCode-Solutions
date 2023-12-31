class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        
        int n = s.length();
        unordered_map<char, int> mp;
        int maxLength = -1;
        
        for(int i=0 ; i<n ; i++) {
            if(mp.find(s[i]) != mp.end()) {
                maxLength = max(maxLength, i - mp[s[i]] - 1);
            }
            else mp[s[i]] = i;
        }
        
        return maxLength;
    }
};