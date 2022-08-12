class Solution {
public:
    // We can represent the set of people who has chosen a hat by a binary array (bit mask). 
    // For example, among 4 people, the 0th and 2nd has chosen their hats, this can be represented as 0101 = 5.
    // Let p be the set of people already chose a hat till this point (in the form of bit mask). 
    // To add the k-th person to the set: p = p | 1<<k.
    // dp[p][current_hat] is the number of ways that the rest of the people can choose hats that satisfy the condition.
    // We have this recursive relation.
    // dp[p][current_hat] = dp[p][current_hat+1] + sum (dp[p | 1<<k][current_hat+1]), for all k such that 
    // the k-th person has not had a hat yet and chooses current_hat.
    // Note that dp[p][current_hat+1] is the number of cases where current_hat is not chosen by any body.
    
    int mod = pow(10, 9) + 7;
    
    int ways(unordered_map<int, vector<int>>& per, int people, int hat, vector<vector<int>>& dp) {
        
        if(people == dp.size()-1) return 1;
        if(hat == 41) return 0;
        if(dp[people][hat] != -1) return dp[people][hat];
        
        int count = ways(per, people, hat+1, dp);
        
        for(auto person : per[hat]) {
            if((people & 1<<person) == 0) {
                int more = people | (1 << person);
                count = (count + ways(per, more, hat+1, dp)) % mod;
            }
        } 
        
        return dp[people][hat] = count;
    }
    
    int numberWays(vector<vector<int>>& hats) {
        
        int n = hats.size();
        if(n == 1) return 1;
        
        unordered_map<int, vector<int>> per;
        for(int i=0 ; i<n ; i++) {
            for(int h : hats[i]) {
                per[h].push_back(i);
            }
        }
        
        vector<vector<int>> dp(1<<n, vector<int>(41, -1));
        return ways(per, 0, 1, dp);
    }
};