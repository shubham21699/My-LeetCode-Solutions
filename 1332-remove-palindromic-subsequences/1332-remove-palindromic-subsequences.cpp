class Solution {
    bool isPalindrome(string s, int i, int j) {
        
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        
        return true;
    }
    
public:
    int removePalindromeSub(string s) {
        
        int n = s.length();
        if(n == 1) return 1;
        if(n == 2) {
            if(s[0] == s[1]) return 1;
            return 2;
        }
        
        if(isPalindrome(s, 0, n-1)) return 1;
        return 2;
    }
};