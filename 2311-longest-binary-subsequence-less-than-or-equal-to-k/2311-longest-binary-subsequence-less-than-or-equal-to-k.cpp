class Solution {
public:
    int longestSubsequence(string s, int k) {
        
        int n = s.length();
        int len = 0;
        int val = 0;
        
        for(int i=n-1 ; i>=0 ; i--) {
            
            if(val + (pow(2, len)) * (s[i] - '0') <= k) {
                val += (pow(2, len)) * (s[i] - '0');
                len++;
            }
            
        }
        
        return len;
    }
};