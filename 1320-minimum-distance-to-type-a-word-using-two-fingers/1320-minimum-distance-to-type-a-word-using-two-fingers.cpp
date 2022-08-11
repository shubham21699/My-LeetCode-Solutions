class Solution {
public:
    int fingDist(int from, int to) {
        
        if(from == 26) return 0;
        
        int r1 = from / 6;
        int c1 = from % 6;
        int r2 = to / 6;
        int c2 = to % 6;
        
        return abs(r1 - r2) + abs(c1 - c2);
    }
    
    int minDist(string& word, int fing1, int fing2, int i, int n, vector<vector<vector<int>>>& dp) {
        
        if(i >= n) return 0;
        if(dp[i][fing1][fing2] != -1) return dp[i][fing1][fing2];
        
        int newPos = word[i]-'A';
        int fing1Dist = fingDist(fing1, newPos);
        int fing2Dist = fingDist(fing2, newPos);
        
        return dp[i][fing1][fing2] = min(fing1Dist + minDist(word, newPos, fing2, i+1, n, dp), fing2Dist + minDist(word, fing1, newPos, i+1, n, dp));
    }
    
    int minimumDistance(string word) {
        
        int n = word.length();
        if(n == 1) return 0;
        if(n == 2) return 0;
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(27, vector<int>(27, -1)));
        return minDist(word, 26, 26, 0, n, dp);
    }
};