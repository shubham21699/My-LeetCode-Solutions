class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0) return false;
        long long int rev = 0;
        long long int copy = x;
        
        while(copy) {
            rev = rev*10 + (copy%10);
            copy /= 10;
        }
        
        if(rev == x) return true;
        return false;
    }
};