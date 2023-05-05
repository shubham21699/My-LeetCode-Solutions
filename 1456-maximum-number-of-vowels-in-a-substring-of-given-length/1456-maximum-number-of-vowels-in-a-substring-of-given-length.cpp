class Solution {
public:
    int maxVowels(string s, int k) {
        
        int n = s.length();
        int result = 0;
        int len = 0;
        int j = 0;
        
        for(int i=0 ; i<n ; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') len++;
            
            if(i >= k-1) {
                result = max(result, len);
                if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') len--;
                j++;
            }
        }
        
        return result;
    }
};