class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        int n = words.size();
        int m = chars.length();
        
        unordered_map<char, int> chrs;
        for(int i=0 ; i<m ; i++) chrs[chars[i]]++;
        
        int count = 0;
        
        for(int i=0 ; i<n ; i++) {
            unordered_map<char, int> mp = chrs;
            bool possible = true;
            
            for(int j=0 ; j<words[i].length() ; j++) {
                if(mp.find(words[i][j]) == mp.end()) {
                    possible = false;
                    break;
                }
                mp[words[i][j]] == 1 ? mp.erase(words[i][j]) : mp[words[i][j]]--;
            }
            
            if(possible) count += words[i].length();
        }
        
        return count;
    }
};