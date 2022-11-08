class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        
        int n = robot.size();
        int m = factory.size();
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        vector<long long> dp(n+1, 1000000000000000);
        dp[0] = 0;
         
        for(int i=0 ; i<m ; i++) {
            for(int k=0 ; k<factory[i][1] ; k++) {
                for(int j=n-1 ; j>=0 ; j--) {
                    dp[j+1] = min(dp[j+1], dp[j] + abs(factory[i][0] - robot[j]));
                }
            }
        }
        
        return dp[n];
    }
};