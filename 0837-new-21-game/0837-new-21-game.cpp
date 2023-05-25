class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        
        Intuition:

        // We can think of the game as a series of draws, where at each draw we can draw any number 
        // from 1 to maxPts with equal probability.
        // To calculate the probability of winning, we use dynamic programming to keep track of the 
        // probabilities for each point.
        // Starting from point 0, we calculate the probabilities for each subsequent point up to N.
        // At each point i, the probability of reaching that point is the sum of probabilities from 
        // the previous maxPts points divided by maxPts.
        // If the current point i is less than K, we add the probability to the windowSum to keep track 
        // of the sum of previous probabilities.
        // If the current point i is greater than or equal to K, we add the probability to the probability
        // variable, which represents the final probability of winning.
        // We maintain a sliding window of size maxPts to efficiently calculate the probabilities, removing 
        // the probability of the point that falls outside the window and adding the probability of the current point.
        // Finally, we return the probability as the result, which represents the probability of winning the game.
        
        if(k == 0 || n >= k+maxPts) return 1.0;
        
        vector<double> dp(n+1);
        dp[0] = 1.0;
        double ans = 0, currSum = 1.0;
        
        for(int i=1 ; i<=n ; i++) {
            
            dp[i] = currSum / maxPts;
            
            if(i < k) currSum += dp[i];
            else ans += dp[i];
            
            if(i - maxPts >= 0) {
                currSum -= dp[i - maxPts];
            }
            
        }
        
        return ans;
    }
};