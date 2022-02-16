class Solution {
public:
    int longestSubstring(string s, int k) {
        
        int n = s.length();
        if(n == 0 || k > n) return 0;
        if(k <= 1) return n;
        
        unordered_map<char, int> m;
        
        for(int i=0 ; i<n ; i++) {
            m[s[i]]++;
        }
        
        int i = 0;
        while(i < n && m[s[i]] >= k) {
            i++;
        }
        if(i == n) return n;
        
        int left = longestSubstring(s.substr(0, i), k);
        
        while(i < n && m[s[i]] < k) {
            i++;
        }
        if(i == n) return left;
        
        int right = longestSubstring(s.substr(i), k);
        
        return max(left, right);
    }
};