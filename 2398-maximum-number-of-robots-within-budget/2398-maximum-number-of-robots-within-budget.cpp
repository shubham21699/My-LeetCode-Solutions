class Solution {
public:
    int find(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget, int i, int n, int k, int& result, int maxChargeTime, long long sum, vector<vector<int>>& dp) {
        
        if(maxChargeTime + (k*sum) <= budget) {
            result = max(result, k);
        }
        if(i >= n) return result;
        if(dp[i][k] != -1) return dp[i][k];
        
        maxChargeTime = max(maxChargeTime, chargeTimes[i]);
        int ans = 0;
        
        // Include this elenent in previous consecutive sequence
        ans = max(ans, find(chargeTimes, runningCosts, budget, i+1, n, k+1, result, maxChargeTime, sum + runningCosts[i], dp));
        
        // Start a new consecutive sequence from here
        ans = max(ans, find(chargeTimes, runningCosts, budget, i+1, n, 1, result, chargeTimes[i], runningCosts[i], dp));
        
        return dp[i][k] = ans;
    }
    
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        
        int n = chargeTimes.size();
        
        // Sliding Window Approach:
        int result = 0;
        int j = 0;
        priority_queue<pair<int, int>> pq;
        long long sum = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            sum += runningCosts[i];
            pq.push({ chargeTimes[i], i });
            
            int k = i-j+1;
            
            while(!pq.empty() && pq.top().first + k*sum > budget) {
                while(!pq.empty() && pq.top().second <= j) pq.pop();
                sum -= runningCosts[j];
                j++;
                k--;
            }
            
            result = max(result, k);
        }
        
        return result;
        
        
        // // OR: Will give TLE from DP Approach
        // int result = 0;
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return find(chargeTimes, runningCosts, budget, 0, n, 0, result, 0, 0, dp);
    }
};