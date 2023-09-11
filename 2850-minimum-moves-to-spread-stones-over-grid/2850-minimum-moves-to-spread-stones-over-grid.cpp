class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        
        int zeros = 0;
        
        for(int i=0 ; i<3 ; i++) {
            for(int j=0 ; j<3 ; j++) {
                if(grid[i][j] == 0) zeros++;
            }
        }
        
        if(zeros == 0) return 0;
        
        int moves = INT_MAX;
        
        for(int i=0 ; i<3 ; i++) {
            for(int j=0 ; j<3 ; j++) {
             
                if(grid[i][j] == 0) {
                    
                    for(int k=0 ; k<3 ; k++) {
                        for(int l=0 ; l<3 ; l++) {
                            
                            if(grid[k][l] > 1) {
                                
                                grid[i][j]++;
                                grid[k][l]--;
                                
                                int dist = abs(k-i) + abs(l-j);
                                moves = min(moves, dist + minimumMoves(grid));
                                
                                grid[i][j]--;
                                grid[k][l]++;
                                
                            }
                            
                        }
                    }
                    
                }
                
            }
        }
        
        return moves;
    }
};