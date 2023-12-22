class Solution {
public:
    int maxScore(string s) {
        
        int n = s.length();
        int ones = 0;
        
        for(int i=0 ; i<n ; i++) {
            if(s[i] == '1') ones++;
        }
        
        int result = 0;
        int zeros = 0;
        
        // We have to divide string into 2 non-empty substring so we traverse till 2nd last index of string
        for(int i=0 ; i<n-1 ; i++) {
            if(s[i] == '0') zeros++;
            else ones--;
            
            result = max(result, zeros + ones);
        }
        
        return result;
    }
};