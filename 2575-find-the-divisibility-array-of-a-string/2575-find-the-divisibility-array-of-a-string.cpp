class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        
        int n = word.length();
        vector<int> result(n);
        long long lastRem = 0;
        
        for(int i=0 ; i<n ; i++) {
            long long currNum = lastRem*10 + (word[i]-'0');
            if(currNum % m == 0) result[i] = 1;
            
            lastRem = currNum % m;
        }
        
        return result;
    }
};