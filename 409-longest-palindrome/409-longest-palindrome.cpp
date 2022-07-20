class Solution {
public:
    int longestPalindrome(string s) {
        
        int n = s.length();
        if(n == 1) return 1;
        unordered_map<char, int> mp;
        
        for(int i=0 ; i<n ; i++) {
            mp[s[i]]++;
        }
        
        int oddCount = 0;
        
        for(auto it=mp.begin() ; it!=mp.end() ; it++) {
            if(it->second % 2 != 0) oddCount++;
        }
        
        // If odd count characters exists then add 1 to it to add that character in the middle.
        return n - oddCount + (oddCount > 0 ? 1 : 0);
    }
};