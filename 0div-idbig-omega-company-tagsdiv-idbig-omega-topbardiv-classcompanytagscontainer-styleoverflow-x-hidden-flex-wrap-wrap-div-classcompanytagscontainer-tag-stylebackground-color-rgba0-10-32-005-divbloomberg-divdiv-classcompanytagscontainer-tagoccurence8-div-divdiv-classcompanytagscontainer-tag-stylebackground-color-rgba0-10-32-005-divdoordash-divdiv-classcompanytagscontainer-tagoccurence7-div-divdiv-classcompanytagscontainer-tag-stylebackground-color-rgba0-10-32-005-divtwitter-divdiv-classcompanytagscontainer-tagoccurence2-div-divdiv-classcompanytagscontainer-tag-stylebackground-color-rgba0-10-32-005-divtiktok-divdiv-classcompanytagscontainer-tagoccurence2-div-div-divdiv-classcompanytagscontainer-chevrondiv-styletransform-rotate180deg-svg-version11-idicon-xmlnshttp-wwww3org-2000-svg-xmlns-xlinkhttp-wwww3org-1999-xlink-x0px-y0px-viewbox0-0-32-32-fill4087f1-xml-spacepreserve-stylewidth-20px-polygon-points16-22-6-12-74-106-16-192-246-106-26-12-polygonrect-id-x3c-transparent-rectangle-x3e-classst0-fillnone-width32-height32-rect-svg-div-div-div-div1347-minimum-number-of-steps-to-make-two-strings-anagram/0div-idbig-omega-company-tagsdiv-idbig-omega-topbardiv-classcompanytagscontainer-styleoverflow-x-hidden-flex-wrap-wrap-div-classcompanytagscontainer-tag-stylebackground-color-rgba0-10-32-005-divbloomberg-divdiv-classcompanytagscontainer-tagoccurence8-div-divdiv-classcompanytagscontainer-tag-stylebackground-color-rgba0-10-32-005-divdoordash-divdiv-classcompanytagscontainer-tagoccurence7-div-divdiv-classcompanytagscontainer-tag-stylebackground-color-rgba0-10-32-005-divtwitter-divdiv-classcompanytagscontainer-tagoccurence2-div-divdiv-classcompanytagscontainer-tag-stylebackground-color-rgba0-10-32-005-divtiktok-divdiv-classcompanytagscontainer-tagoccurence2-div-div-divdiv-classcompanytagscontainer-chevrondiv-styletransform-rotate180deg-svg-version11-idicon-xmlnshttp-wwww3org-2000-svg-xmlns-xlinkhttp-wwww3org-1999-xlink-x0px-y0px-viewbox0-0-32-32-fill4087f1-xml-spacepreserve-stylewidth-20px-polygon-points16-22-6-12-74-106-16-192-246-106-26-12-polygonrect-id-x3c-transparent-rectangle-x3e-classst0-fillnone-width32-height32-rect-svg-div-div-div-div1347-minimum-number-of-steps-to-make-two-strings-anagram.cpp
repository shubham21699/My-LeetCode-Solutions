class Solution {
public:
    int minSteps(string s, string t) {
        
        int n = s.length();
        unordered_map<char, int> mp;
        
        for(int i=0 ; i<n ; i++) {
            mp[s[i]]++;
            mp[t[i]]--;
        }
        
        int steps = 0;
        
        for(auto it : mp) {
            // These are not matched characters in string t which needs to be replaced.
            if(it.second < 0) steps += abs(it.second);
        }
        
        return steps;
    }
};