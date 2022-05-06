class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
        int n = s.length();
        int count1s = 0;
        int countFlips = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            if(s[i] == '1') count1s++;
            else countFlips++;
            
            countFlips = min(countFlips, count1s);
        }
        
        return countFlips;
    }
};