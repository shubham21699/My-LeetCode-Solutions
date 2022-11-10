class Solution {
public:
    string removeDuplicates(string s) {
        
        int n = s.length();
        int i = 0;
        
        while(i < n) {
            
            if(i<n-1 && s[i] == s[i+1]) {
                s.erase(i, 2);
                if(i>0) i--;
                n -= 2;
            }
            else i++;
            
        }
        
        return s;
    }
};