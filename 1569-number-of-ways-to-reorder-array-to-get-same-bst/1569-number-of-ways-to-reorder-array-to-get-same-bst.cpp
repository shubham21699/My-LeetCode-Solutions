class Solution {
    vector<vector<long long>> dp;
    long long MOD = 1e9 + 7;

    unsigned long long solve(vector<int> &nums) {
        
        int k = nums.size();
        if (k <= 1) return 1;
        vector<int> l, r;
        
        for (int i=1; i<k; i++) {
            if (nums[i] > nums[0]) r.push_back(nums[i]);
            else l.push_back(nums[i]);
        }
        
        int n = l.size(), m = r.size();
        
        return solve(l) * solve(r) % MOD * dp[n + m][n] % MOD;
    }

public:
    int numOfWays(vector<int> &nums) {
        
        int n = nums.size();
        dp = vector<vector<long long>>(n + 1, vector<long long>(n + 1, 0));
        
        for (int i=1; i<n+1; i++) {
            dp[i][0] = 1;
            dp[i][1] = i;
            dp[i][i - 1] = i;
            dp[i][i] = 1;
        }
        
        for (int i=2; i<n+1; i++) {
            for (int j=2; j<n+1; j++) {
                if (i >= j) dp[i][j] = (dp[i - 1][j - 1] % MOD + dp[i - 1][j] % MOD) % MOD;
                else break;
            }
        }
        
        return solve(nums) - 1;
    }
};