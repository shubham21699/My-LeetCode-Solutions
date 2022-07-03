class Solution {
public:
    string decodeMessage(string key, string message) {
        
        int n = key.length();
        int m = message.length();
        unordered_map<char, char> mp;
        int i = 0;
        
        for(int j=0 ; j<n ; j++) {
            if(key[j] == ' ' || mp.find(key[j]) != mp.end()) continue;
            else {
                mp[key[j]] = 'a' + (i % 26);
                i++;
            }
        }
        
        string res = "";
        for(int j=0 ; j<m ; j++) {
            if(message[j] == ' ') res += ' ';
            else res += mp[message[j]];
        }
        
        return res;
    }
};