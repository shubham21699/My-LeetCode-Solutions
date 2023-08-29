class Solution {
public:
    int binarySearch(vector<vector<int>>& offers, int ind, int m, int val) {
        
        int left = ind, right = m-1;
        int ans = -1;
        
        while(left <= right) {
            int mid = left + (right - left)/2;
            
            if(offers[mid][0] > val) {
                ans = mid;
                right = mid-1;
            }
            else left = mid+1;
        }
        
        return ans;
    }
    
    int maxProfit(vector<vector<int>>& offers, int ind, int m, int n, vector<int>& dp) {
        
        if(ind >= m) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        int notTaken = maxProfit(offers, ind+1, m, n, dp);
        
        int nextInd = binarySearch(offers, ind+1, m, offers[ind][1]);
        int taken = offers[ind][2] + (nextInd == -1 ? 0 : maxProfit(offers, nextInd, m, n, dp));
        
        return dp[ind] = max(taken, notTaken);
    }
    
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        
        int m = offers.size();
        sort(offers.begin(), offers.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });
        
        vector<int> dp(m, -1);
        return maxProfit(offers, 0, m, n, dp);
    }
};