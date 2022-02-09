class Solution {
public:
    bool isPalindrome(string s) {
        
        int n = s.length();
        if(n <= 1) return true;
        
        int i = 0;
        int j = n-1;

        while(i < j) {
            
            while(!isalnum(s[i]) && i<j) i++;
            while(!isalnum(s[j]) && i<j) j--;
            if(tolower(s[i]) != tolower(s[j])) return false;
            
            i++;
            j--;
        }
        
        return true;
    }
};