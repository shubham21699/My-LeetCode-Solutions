class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        set<pair<int, int>> st;
        
        for(int i=0 ; i<n ; i++) {
            if(grid[i][i] == 0) return false;
            if(grid[i][m-i-1] == 0) return false;
            st.insert({ i, i });
            st.insert({ i, m-i-1 });
        }
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                if(st.find({ i, j }) != st.end()) continue;
                if(grid[i][j] != 0) return false;
            }
        }
        
        return true;
    }
};