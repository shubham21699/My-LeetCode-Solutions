class Solution {
public:
    int largestVariance(string s) {
        
        int n = s.length();
        int maxVar = 0;
        unordered_set<char> letters(s.begin(), s.end());
        
        for(int k=1 ; k<=2 ; k++) {  // Perform the calculation twice (forward and backward)
            for(char l1 : letters) {
                for(char l2 : letters) {
                    
                    if(l1 == l2) continue;
                    
                    int count1 = 0, count2 = 0;
                    
                    for(char x : s) {
                        if(x == l1) count1++;
                        else if(x == l2) count2++;
                        
                        if(count2 > count1) { // Reset count1 and count2 if count2 becomes greater than count1
                            count1 = count2 = 0;
                        }
                        else if(count1 > 0 && count2 > 0) {
                            maxVar = max(maxVar, count1 - count2);
                        }
                    }
                    
                }
            }
            
            reverse(s.begin(), s.end());
        }
        
        return maxVar;
    }
};