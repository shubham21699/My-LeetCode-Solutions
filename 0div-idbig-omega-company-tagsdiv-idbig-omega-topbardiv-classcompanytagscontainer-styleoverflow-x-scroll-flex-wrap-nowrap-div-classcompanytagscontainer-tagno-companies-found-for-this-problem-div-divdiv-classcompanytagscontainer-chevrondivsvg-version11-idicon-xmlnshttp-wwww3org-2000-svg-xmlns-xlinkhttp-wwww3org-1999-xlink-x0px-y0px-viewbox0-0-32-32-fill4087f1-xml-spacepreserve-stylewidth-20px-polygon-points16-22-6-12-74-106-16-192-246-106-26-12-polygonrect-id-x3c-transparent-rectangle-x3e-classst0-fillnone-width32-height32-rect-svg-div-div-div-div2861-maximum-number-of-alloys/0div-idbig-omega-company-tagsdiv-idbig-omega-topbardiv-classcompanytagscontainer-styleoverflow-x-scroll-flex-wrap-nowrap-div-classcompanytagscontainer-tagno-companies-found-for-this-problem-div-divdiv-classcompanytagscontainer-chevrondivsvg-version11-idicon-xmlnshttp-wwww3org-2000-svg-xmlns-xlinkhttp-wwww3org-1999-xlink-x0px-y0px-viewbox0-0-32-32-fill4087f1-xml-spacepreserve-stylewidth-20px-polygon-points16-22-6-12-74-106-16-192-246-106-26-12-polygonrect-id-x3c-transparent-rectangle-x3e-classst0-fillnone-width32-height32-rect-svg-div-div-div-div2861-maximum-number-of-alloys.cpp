class Solution {
public:
    bool check(vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost, int n, int k, int fixed_alloy, int budget) {

        long long total = INT_MAX;
        
        for(int i=0 ; i<k ; i++) {
            long long currCost = 0;
            
            for(int j=0 ; j<n ; j++) {
                long long required = (long long) fixed_alloy * composition[i][j];
                
                if(stock[j] >= required) continue;
                
                long long extra = (required - stock[j]) * cost[j];
                currCost += extra;
            }
            
            total = min(total, currCost);
            if(total <= budget) return true;
        }
        
        return false;
    }
    
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        
        int low = 0;
        int high = 1e9;
        int ans = -1;
        
        while(low <= high) {
            
            int mid = low + (high - low)/2;
            
            if(check(composition, stock, cost, n, k, mid, budget)) {
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
            
        }
        
        return ans;
    }
};