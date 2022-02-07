class Solution {
public:
    char findTheDifference(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        char bit = t[m-1];
        
        for(int i=0 ; i<n ; i++) {
            bit ^= s[i];
            bit ^= t[i];
        }
        
        return bit;
    }
};