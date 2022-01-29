class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int n = s.length();
        int m = p.length();
        vector<int> result;
        if(m > n) return result;
        
        unordered_map<char, int> target;
        unordered_map<char, int> current;
        
        for(int j=0 ; j<m ; j++) {
            target[p[j]]++;
        }
        
        for(int i=0 ; i<n ; i++) {
            
            current[s[i]]++;
            
            // If we exceeds given Anagram P window size, then remove character appears before window starts
            // ex. if anagram size is 3 and i reach at 3 (0 indexing) means to make it to anagram's window
            // size, then element at i-m i.e. 3-3 = 0th element is out of our window size so discard it.
            if(i >= m) current[s[i-m]] == 1 ? current.erase(s[i-m]) : current[s[i-m]]--;
            
            if(current == target) result.push_back(i-m+1);
            
        }
        
        return result;
    }
};