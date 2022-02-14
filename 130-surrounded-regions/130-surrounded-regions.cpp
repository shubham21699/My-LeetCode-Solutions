class Solution {
    void dfs(vector<vector<char> >& board, int i, int j, int n, int m) {
        
        // Convert those '0' to '#' which doesn't have to flip.
        board[i][j] = '#';
        if(i+1<n && board[i+1][j] == 'O') dfs(board, i+1, j, n, m);
        if(j+1<m && board[i][j+1] == 'O') dfs(board, i, j+1, n, m);
        if(i-1>=0 && board[i-1][j] == 'O') dfs(board, i-1, j, n, m);
        if(j-1>=0 && board[i][j-1] == 'O') dfs(board, i, j-1, n, m);
    }
    
public:
    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        
        if(n == 1 && m == 1) return;
        
        // Check for the existence of regions on border:
        // Check 1st and last row
        for(int j=0 ; j<m ; j++) {
            if(board[0][j] == 'O') dfs(board, 0, j, n, m);
            if(board[n-1][j] == 'O') dfs(board, n-1, j, n, m);
        }
        
        // Check for 1st and last column
        for(int i=0 ; i<n ; i++) {
            if(board[i][0] == 'O') dfs(board, i, 0, n, m);
            if(board[i][m-1] == 'O') dfs(board, i, m-1, n, m);
        }
        
        // Flips '0' to 'X' and '0' back from '#'
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
        
    }
};