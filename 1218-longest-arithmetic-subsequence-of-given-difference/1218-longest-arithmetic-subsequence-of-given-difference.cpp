class Solution {
public:
    int ls(vector<int>& arr, int i, int n, int difference, int prev, unordered_map<int, unordered_map<int, int>>& dp) {
        
        if(i >= n) return 0;
        if(dp.find(i) != dp.end() && dp[i].find(prev+1) != dp[i].end()) return dp[i][prev+1];
        
        int include = 0;
        
        if(prev == -1 || arr[i]-arr[prev] == difference) 
            include = 1 + ls(arr, i+1, n, difference, i, dp);
        
        int exclude = ls(arr, i+1, n, difference, prev, dp);
        
        return dp[i][prev+1] = max(include, exclude);
    }
    
    int longestSubsequence(vector<int>& arr, int difference) {
        
        int n = arr.size();
        if(n == 1) return 0;
        
        unordered_map<int, int> length;
        int lsLen = 1;
        
        for(int i=0 ; i<n ; i++) { 
            length[arr[i]] = 1 + length[arr[i] - difference];
            lsLen = max(lsLen, length[arr[i]]);
        }
        
        return lsLen;
        
        // // OR: Will give TLE
        // unordered_map<int, unordered_map<int, int>> dp;
        // return ls(arr, 0, n, difference, -1, dp);
    }
};