class Solution {
public:
    int dfs(vector<vector<int>> grid, int i, int j, int n, int m, int val, set<pair<int, int>>& visited) {
        
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] >= val) return 0;
        if(visited.find({ i, j }) != visited.end()) return 0;
        
        visited.insert({ i, j });
        
        return 1 + dfs(grid, i+1, j, n, m, val, visited) + dfs(grid, i, j+1, n, m, val, visited) +
                   dfs(grid, i-1, j, n, m, val, visited) + dfs(grid, i, j-1, n, m, val, visited);
    }
    
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        
        /*Intuition :-
        Traverse the grid from the top-left cell. In the meantime, use a priority queue to keep track 
        of the largest value required to reach a cell. A separate counter is updated to indicate how many cells
        accessible prior to arriving at the current cell. 
        This information is kept in an array via a value-count pair.
        For each queries, binary search the array to find the number of cells whose corresponding value 
        is strictly smaller than the given query.*/
        
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dir = {-1, 0, 1, 0, -1};
        int prefix = 0;
        int prev = INT_MIN; 
        
        vector<pair<int, int>> point; 
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; 
        pq.push({ grid[0][0], 0, 0 }); 
        grid[0][0] = 0; 
        
        while (!pq.empty()) {
            
            auto x = pq.top(); 
            int v = x[0];
            int i = x[1];
            int j = x[2];
            pq.pop(); 
            
            if (prev != v) point.push_back({ prev, prefix }); 
            
            prefix++; 
            prev = v; 
            
            for (int k = 0 ; k < 4 ; k++) {
                int newi = i + dir[k];
                int newj = j + dir[k+1]; 
                
                if (0 <= newi && newi < n && 0 <= newj && newj < m && grid[newi][newj]) {
                    int vv = max(v, grid[newi][newj]); 
                    pq.push({ vv, newi, newj }); 
                    grid[newi][newj] = 0; 
                }
                
            }
        }
        
        point.push_back({ prev, prefix }); 
        
        int k = queries.size();
        vector<int> result; 
        
        for(int i=0 ; i<k ; i++) {
            auto it = lower_bound(point.begin(), point.end(), make_pair(queries[i], 0)); 
            result.push_back((--it)->second); 
        }
        
        return result; 
        
        
//         // OR: Will give TLE
//         int n = grid.size();
//         int m = grid[0].size();
//         int k = queries.size();
//         vector<int> result(k);
//         unordered_map<int, int> mp;
        
//         for(int i=0 ; i<k ; i++) {
//             set<pair<int, int>> visited;
//             if(mp.find(queries[i]) != mp.end()) result[i] = mp[queries[i]]; 
//             else {
//                 result[i] = dfs(grid, 0, 0, n, m, queries[i], visited);
//                 mp[queries[i]] = result[i];
//             }
//         }
        
//         return result;
    }
};