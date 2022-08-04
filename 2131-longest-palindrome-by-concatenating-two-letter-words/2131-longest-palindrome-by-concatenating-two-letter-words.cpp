class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        int n = words.size();
        if(n == 1) return words[0][0]==words[0][1] ? 2 : 0;
        
        unordered_map<string, int> mp;
        for(int i=0 ; i<n ; i++) mp[words[i]]++;
        
        int lpLen = 0;
        bool oddLenSameLettersMidPart = false;
        
        for(int i=0 ; i<n ; i++) {
            
            string x = words[i];
            reverse(x.begin(), x.end());
            
            if(mp.find(words[i]) != mp.end() && mp.find(x) != mp.end() && words[i] != x) {
                lpLen += 4;
                mp[words[i]] == 1 ? mp.erase(words[i]) : mp[words[i]]--;
                mp[x] == 1 ? mp.erase(x) : mp[x]--;
            }
            else if(mp.find(words[i]) != mp.end() && words[i][0] == words[i][1]) {
                if(mp[x] % 2 == 0) {
                    lpLen += 2 * mp[words[i]];
                    mp.erase(words[i]);
                }
                else {
                    lpLen += 2 * (mp[words[i]]-1);
                    oddLenSameLettersMidPart = true;
                    mp.erase(words[i]);
                }
            }
            
        }
        
        if(oddLenSameLettersMidPart) lpLen += 2;
        
        return lpLen;
    }
};