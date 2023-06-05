class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int n = coordinates.size();
        if(n == 2) return true;
        
        int xDist = coordinates[1][0] - coordinates[0][0];
        int yDist = coordinates[1][1] - coordinates[0][1];
        
        for(int i=2 ; i<n ; i++) {
            if((xDist == 0 && coordinates[i][0] - coordinates[i-1][0] == 0) || (yDist == 0 && coordinates[i][1] - coordinates[i-1][1] == 0)) continue;
            
            int x = coordinates[i][0] - coordinates[i-1][0];
            int y = coordinates[i][1] - coordinates[i-1][1];
            
            if(y * xDist != x * yDist) return false;
        }
        
        return true;
    }
};