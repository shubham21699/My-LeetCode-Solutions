class Solution {
public:
    bool validPalindrome(string s) {
        
        int n = s.length();
        int i = 0;
        int j = n-1;
        int count = 0;
        
        while(i < j) {
            if(s[i] != s[j]) {
                
                int i1 = i;
                int i2 = i+1;
                int j1 = j;
                int j2 = j-1;
                
                while(i1 < j2 && s[i1] == s[j2]) {
                    i1++;
                    j2--;
                } 
                
                while(i2 < j1 && s[i2] == s[j1]) {
                    i2++;
                    j1--;
                }
                
                return i1>=j2 || i2>=j1;
                
            }
            else {
                i++;
                j--;
            }
        }
        
        return true;
    }
};