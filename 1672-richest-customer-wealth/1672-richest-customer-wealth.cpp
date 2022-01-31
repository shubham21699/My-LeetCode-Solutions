class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int n = accounts.size();
        int m = accounts[0].size();
        int maxWealth = 0;
        
        for(int i=0 ; i<n ; i++) {
            maxWealth = max(maxWealth, accumulate(accounts[i].begin(), accounts[i].end(), 0));
        }
        
        return maxWealth;
        
//         OR:
//         for(int i=0 ; i<n ; i++) {
            
//             int wealth = 0;
            
//             for(int j=0 ; j<m ; j++) {
//                 wealth += accounts[i][j];
//             }
            
//             maxWealth = max(maxWealth, wealth);
            
//         }
        
//         return maxWealth;
    }
};