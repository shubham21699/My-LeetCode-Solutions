class Solution {
public:
    int mod = pow(10, 9) + 7;
    
    int countHomogenous(string s) {
        
        int n = s.length();
        string t = "";
        int count = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            t += s[i];
            
            if(i == n-1 || (i < n-1 && s[i] != s[i+1])) {
                int m = t.length();
                count = (count + (1LL * m * (m+1)) / 2) % mod;
                t = "";
            } 
            
        }
        
        return count;
    }
};