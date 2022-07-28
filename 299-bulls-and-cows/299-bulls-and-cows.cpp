class Solution {
public:
    string getHint(string secret, string guess) {
        
        int n = secret.size();
        int bulls = 0;
        int cows = 0;
        
        unordered_map<char, int> mp;
        for(int i=0 ; i<n ; i++) {
            if(secret[i] == guess[i]) continue;
            mp[secret[i]]++;
        }
        
        for(int i=0 ; i<n;  i++) {
            if(secret[i] == guess[i]) bulls++;
            else if(mp.find(guess[i]) != mp.end()) {
                cows++;
                mp[guess[i]] == 1 ? mp.erase(guess[i]) : mp[guess[i]]--;
            }
        }
        
        string res = to_string(bulls) + "A" + to_string(cows) + "B";
        return res;
    }
};