class Solution {
public:
    string breakPalindrome(string palindrome) {
        
        int n = palindrome.length();
        if(n == 1) return "";
        
        bool flag = false;
        
        for(int i=0 ; i<n/2 ; i++) {
            
            if(palindrome[i] != 'a') {
                palindrome[i] = 'a';
                flag = true;
                break;
            }
            
        }
        
        if(!flag) palindrome[n-1] = 'b';
        return palindrome;
    }
};