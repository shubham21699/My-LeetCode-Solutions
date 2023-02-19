class Solution {
public:
    int minMaxDifference(int num) {
        
        string s = to_string(num);
        int nonZero = -1, nonNine = -1;
        int max = 0, min = 0;
        
        for(int i=0 ; i<s.length() ; i++) {
            if(nonZero == -1 && s[i] != '0') {
                nonZero = s[i];
                min = min*10 + 0;
            }
            else min = min*10 + (s[i] == nonZero ? 0 : s[i]-'0');
            
            if(nonNine == -1 && s[i] != '9') {
                nonNine = s[i];
                max = max*10 + 9;
            }
            else max = max*10 + (s[i] == nonNine ? 9 : s[i]-'0');
            
        }

        return max - min;
    }
};