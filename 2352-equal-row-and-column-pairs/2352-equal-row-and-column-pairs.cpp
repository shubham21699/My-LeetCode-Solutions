class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int n = grid.size();
        map<vector<int>, int> mp;
        
        for(int j=0 ; j<n ; j++) {
            vector<int> curr;
            for(int i=0 ; i<n ; i++) curr.push_back(grid[i][j]);
            
            mp[curr]++;
        }
        
        int pairs = 0;
        
        for(int i=0 ; i<n ; i++) {
            if(mp.find(grid[i]) != mp.end()) pairs += mp[grid[i]];
        }
        
        return pairs;
    }
};