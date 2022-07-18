class Solution {
public:
    bool check(vector<vector<char>>& board, int i, int j, char val) {
        
        int row = i - i%3;
        int col = j - j%3;
        
        // Checking Row:
        for(int x=0 ; x<9 ; x++) {
            if(board[x][j] == val) return false;
        }
        
        // Checkking Column:
        for(int y=0 ; y<9 ; y++) {
            if(board[i][y] == val) return false;
        }
        
        // Checking Sub-Box:
        for(int x=0 ; x<3 ; x++) {
            for(int y=0 ; y<3 ; y++) {
                if(board[row+x][col+y] == val) return false;
            }
        }
        
        return true;
    }
    
    bool solve(vector<vector<char>>& board, int i, int j) {
        
        if(i == 9) return true;
        if(j == 9) return solve(board, i+1, 0);
        if(board[i][j] != '.') return solve(board, i, j+1);
        
        for(char val='1' ; val<='9' ; val++) {
            if(check(board, i, j, val)) {
                board[i][j] = val;
                if(solve(board, i, j+1)) return true;
                board[i][j] = '.';
            }
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board, 0, 0);
    }
};