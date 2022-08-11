class Solution {
public:
    vector<int> dx = { 1, 0, -1, 0 };
    vector<int> dy = { 0, 1, 0, -1 };
    int dp[8][8][8][8][1001] = { -1 };
    
    bool whoWin(vector<string>& grid, int catRowInd, int mouseRowInd, int catColInd, int mouseColInd, int n, int m, int catJump, int mouseJump, int turns) {
        
        // If Cat Wins
        if(mouseRowInd == catRowInd && mouseColInd == catColInd) return false;
        if(turns >= 128) return false; 
        if(grid[catRowInd][catColInd] == 'F') return false; 
        
        // If Mouse Wins
        if(grid[mouseRowInd][mouseColInd] == 'F') return true; 
        
        if(dp[catRowInd][catColInd][mouseRowInd][mouseColInd][turns] != -1) 
            return dp[catRowInd][catColInd][mouseRowInd][mouseColInd][turns];
        
        
        if(turns % 2 == 0) { // Mouse Turns
            
            for(int i=0 ; i<4 ; i++) {
                for(int j=0 ; j<=mouseJump ; j++) {
                    
                    int newMouseRowInd = mouseRowInd + j*dx[i];
                    int newMouseColInd = mouseColInd + j*dy[i];
                    
                    if(newMouseRowInd >= 0 && newMouseRowInd < n && newMouseColInd >= 0 && newMouseColInd < m && grid[newMouseRowInd][newMouseColInd] != '#') {
                       
                        if(whoWin(grid, catRowInd, newMouseRowInd, catColInd, newMouseColInd, n, m, catJump, mouseJump, turns+1)) {
                            return dp[catRowInd][catColInd][mouseRowInd][mouseColInd][turns] = true;
                        }
                        
                    }
                    else break;
                    
                }
                
            }
            
            return dp[catRowInd][catColInd][mouseRowInd][mouseColInd][turns] = false;
        }
        else { // Cats Turn
            
            for(int i=0 ; i<4 ; i++) {
                for(int j=0 ; j<=catJump ; j++) {
                    
                    int newCatRowInd = catRowInd + j*dx[i];
                    int newCatColInd = catColInd + j*dy[i];

                    if(newCatRowInd >= 0 && newCatRowInd < n && newCatColInd >= 0 && newCatColInd < m && grid[newCatRowInd][newCatColInd] != '#') {

                        if(!whoWin(grid, newCatRowInd, mouseRowInd, newCatColInd, mouseColInd, n, m, catJump, mouseJump, turns+1)) {
                            return dp[catRowInd][catColInd][mouseRowInd][mouseColInd][turns] = false;
                        }
                        
                    }
                    else break;

                }
                
            }
            
            return dp[catRowInd][catColInd][mouseRowInd][mouseColInd][turns] = true;
        }
     
        return dp[catRowInd][catColInd][mouseRowInd][mouseColInd][turns];
    }
    
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        memset(dp, -1, sizeof(dp));
        
        int catRowInd, mouseRowInd, catColInd, mouseColInd;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                if(grid[i][j] == 'C') {
                    catRowInd = i;
                    catColInd = j;
                }
                else if(grid[i][j] == 'M') {
                    mouseRowInd = i;
                    mouseColInd = j;
                }
            }
        }
        
        return whoWin(grid, catRowInd, mouseRowInd, catColInd, mouseColInd, n, m, catJump, mouseJump, 0);
    }
};