class Solution {
public:
    string makeGood(string s) {
        
        int n = s.length();
        int i = 0;
        
        while(i < n) {
            if(i<n-1 && ((islower(s[i]) && isupper(s[i+1])) || (isupper(s[i]) && islower(s[i+1]))) && tolower(s[i]) == tolower(s[i+1])) {
                s.erase(i, 2);
                n -= 2;
                if(i > 0) i--;
            }
            else i++;
        }
        
        return s;
    }
};