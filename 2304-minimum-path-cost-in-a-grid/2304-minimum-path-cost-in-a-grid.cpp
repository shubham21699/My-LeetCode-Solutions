class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        unordered_map<int, vector<int>> mp;
        for(int i=0 ; i<moveCost.size() ; i++) {
            mp[i] = moveCost[i];
        }
        
        vector<vector<int>> result(grid);
        
        int minCost = INT_MAX;
        
        for(int i=1 ; i<m ; i++) {
            for(int j=0 ; j<n ; j++) {
                int cost = INT_MAX;
                for(int k=0 ; k<n ; k++) {
                    vector<int> v = moveCost[grid[i-1][k]];
                    cost = min(cost, result[i-1][k] + v[j]);
                }
                
                result[i][j] += cost;
            }
        }
        
        return *min_element(result[m-1].begin(), result[m-1].end());
    }
};