class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        
        int n = s.length();
        int count_1 = 0;
        
        for(int i=0 ; i<n ; i++) {
            if(s[i] == '1') {
                count_1++;
                s[i] = '0';
            }
        }
        
        s[n-1] = '1';
        count_1--;
        
        int i = 0;
        while(count_1) {
            s[i] = '1';
            count_1--;
            i++;
        }
        
        return s;
    }
};