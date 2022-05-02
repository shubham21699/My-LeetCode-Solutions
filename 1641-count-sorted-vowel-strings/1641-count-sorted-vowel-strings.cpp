class Solution {
    unordered_map<int, map<int, int>> dp; // For Memoization
    
    int calc(int n, string s, vector<string>& vowels, int index) {
        
        if(index >= 5) return 0;
        if(s.size() == n) return 1;
        
        if(dp[index][s.size()]) return dp[index][s.size()];
        
        return dp[index][s.size()] = calc(n, s+vowels[index], vowels, index) + calc(n, s, vowels, index+1);
    }
    
public:
    int countVowelStrings(int n) {
        
        if(n == 1) return 5;
        
        vector<string> vowels = {"a", "e", "i", "o", "u"};
        string s = "";
        
        return calc(n, s, vowels, 0);
    }
};