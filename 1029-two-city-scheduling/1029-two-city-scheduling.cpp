class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int n = costs.size();
        sort(costs.begin(), costs.end(), [](vector<int> a, vector<int> b) {
            return (a[0] - a[1]) < (b[0] - b[1]); 
        });
        
        int cost = 0;
        
        for(int i=0 ; i<n ; i++) {
            if(i<n/2) cost += costs[i][0];
            else cost += costs[i][1];
        }
        
        return cost;
    }
};