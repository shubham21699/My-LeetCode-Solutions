class Solution {
public:    
    int takeCharacters(string s, int k) {

        int n = s.length();
        if(k == 0) return 0;
        if(n < 3) return -1;
        
        /* Find the maximum window size of the string such that count of all A,B,C chars in rest of the 
        string is atleast K
        
        Why taking maximum ?
        Because we need to find minimum number of minutes taking char from left or right side such all 
        a, b, c char are at least K.
        
        By taking max. window in middle we get smaller window in left and right side.*/
        
        
        unordered_map<char, int> freq;
        for(int i=0 ; i<n ; i++) freq[s[i]]++;
        
        if(freq['a'] < k || freq['b'] < k || freq['c'] < k) return -1;
        
        // This is the window size of that part of string which is extra i.e. not required to consider 
        int windowSize = 0;
        
        int ans = n;
        int j = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            freq[s[i]]--;
            windowSize++;
            
            while(freq[s[i]] < k) {
                freq[s[j]]++;
                j++;
                windowSize--;
            }
            
            // This is the maximum size of window such that all chars beyond this window
            // are occurs atleast k times.
            ans = min(ans, n-windowSize);
        }
        
        return ans;
    }
};