class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.length();
        unordered_map<int, int> mp;
        int result = 0;
        int maxFreq = 0;
        
        for(int i=0 ; i<n ; i++) {
            mp[s[i]]++;
            maxFreq = max(maxFreq, mp[s[i]]);
            
            if(result - maxFreq < k) result++;
            else mp[s[i - result]]--;
        }
        
        return result;
    }
};