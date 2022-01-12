class Solution {
    void getCoordinates(int n, int startIndex, int& row, int& col) {
        
        row = n - 1 - (startIndex-1)/n;
        col = (startIndex-1) % n;
        
        if((row%2 == 0 && n%2 == 0) || (row%2 == 1 && n%2 == 1)) {
            col = n - 1 - col;
        }
        
    }
    
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int n = board.size();
        if(n == 2) return 1;
        
        vector<bool> visited(n*n + 1, false);
        visited[1] = true;
        
        queue<pair<int, int> > q;
        q.push({ 1, 0 });
        
        while(!q.empty()) {
            
            pair<int, int> p = q.front();
            q.pop();
            
            int startIndex = p.first;
            int distance = p.second;
            int row, col;
            
            if(startIndex == n*n) return distance; // Reached the destination
            
            for(int i=1 ; startIndex+i<=n*n && i<=6 ; i++) {
                
                getCoordinates(n, startIndex+i, row, col);
                
                // Check for snake or ladder 
                int sFinal = board[row][col] == -1 ? startIndex+i : board[row][col];
                
                if(!visited[sFinal]) {
                    visited[sFinal] = true;
                    q.push({ sFinal, distance+1 });
                }
                
            }
            
        }
       
       return -1; 
    }
};