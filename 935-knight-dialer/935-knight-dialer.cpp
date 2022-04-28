class Solution {
    long mod = pow(10,9) + 7;
    
    int solve(vector<vector<int>>& mp, int i, int n, vector<vector<int>>& dp) {
        
        if(n == 1) return 1;
        if(dp[i][n] != -1) return dp[i][n];
        
        int ans = 0;
        
        for(auto x : mp[i]) {
            ans = ( ans + solve(mp, x, n-1, dp)) % mod;
        }
        
        return dp[i][n] = ans;
    }
    
    int count(int n, vector<vector<char>>& pad, int i, int j, vector<vector<vector<long>>>& dp) {
        
        if(i<0 || j<0 || i>=4 || j>=3 || pad[i][j] == '*' || pad[i][j] == '#')
            return 0;
        
        if(n == 1) return 1;
        if(dp[i][j][n] > 0) return dp[i][j][n];
        
        long ans = count(n-1, pad, i-2, j+1, dp)%mod + 
            count(n-1, pad, i-1, j+2, dp)%mod +
            count(n-1, pad, i+1, j+2, dp)%mod +
            count(n-1, pad, i+2, j+1, dp)%mod +
            count(n-1, pad, i+2, j-1, dp)%mod +
            count(n-1, pad, i+1, j-2, dp)%mod +
            count(n-1, pad, i-1, j-2, dp)%mod +
            count(n-1, pad, i-2, j-1, dp)%mod;
        
        return dp[i][j][n] = ans%mod;
    }
    
public:
    int knightDialer(int n) {
        
        if(n == 1) return 10;
        
        vector<vector<char>> pad(4, vector<char>(3));
        int x = 1;
        
        for(int i=0 ; i<3 ; i++) {
            for(int j=0 ; j<3 ; j++) {
                pad[i][j] = x+'0';
                x++;
            }
        }
        
        // We don't have to visit this place.
        pad[3][0] = '*';
        pad[3][2] = '#';
        
        long result = 0;
        vector<vector<vector<long>>> dp(4, vector<vector<long>>(3, vector<long>(n+1, 0)));
        
        for(int i=0 ; i<4 ; i++) {
            for(int j=0 ; j<3 ; j++) {
                if(pad[i][j] == '*' || pad[i][j] == '#') continue;
                
                result += (count(n, pad, i, j, dp) % mod);
                result %= mod;
            }
        }
        
        return result;
        
        
//         // OR: 
//         unordered_map<int, vector<int>> mp;
//         vector<vector<int>> mp(10);
//         mp[0] = {4, 6};
//         mp[1] = {6, 8};
//         mp[2] = {7, 9};
//         mp[3] = {4, 8};
//         mp[4] = {0, 3, 9};
//         mp[6] = {0, 1, 7};
//         mp[7] = {2, 6};
//         mp[8] = {1, 3};
//         mp[9] = {2, 4};
        
//         vector<vector<int>> dp(10, vector<int>(n+1, -1));
//         int result = 0;
        
//         for(int i=0 ; i<10 ; i++) {
//             if(i == 5) continue;
//             result = (result + solve(mp, i, n, dp)) % mod;
//             // result %= mod;
//         }
        
//         return result;
    }
};