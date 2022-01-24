class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int n = word.length();
        unordered_map<int, int> m;
        
        for(int i=0 ; i<n ; i++) {
            if(isupper(word[i])) m[1]++;
            else if(islower(word[i])) m[2]++;
        }
        
        if(m[1] == 1 && isupper(word[0])) return true;
        if(m[1] == n || m[2] == n) return true;
        return false;
    }
};