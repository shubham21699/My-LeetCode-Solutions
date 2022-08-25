class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        int n = ransomNote.size();
        int m = magazine.size();
        
        if(ransomNote == magazine) return true;
        
        unordered_map<char, int> mp;
        for(int i=0 ; i<m ; i++) mp[magazine[i]]++;
        
        for(int i=0 ; i<n ; i++) {
            if(mp.find(ransomNote[i]) == mp.end()) return false;
            
            mp[ransomNote[i]] == 1 ? mp.erase(ransomNote[i]) : mp[ransomNote[i]]--;
        }
        
        return true;
    }
};