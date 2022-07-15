class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        
        int n = moves.size();
        vector<vector<char>> board(3, vector<char>(3, '.'));
        int turn = 1;       
        int x = 0;
        int z = 0;
        
        for(int k=0 ; k<n ; k++) {
            int i = moves[k][0]; 
            int j = moves[k][1];
            board[i][j] = turn%2 != 0 ? 'X' : 'O';
            
            if(board[i][j] == 'X') {
                if(k>=4 && (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') || 
                   (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') || 
                   (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') || 
                   (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') || 
                   (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') || 
                   (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') || 
                   (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || 
                   (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')) return "A";
                
                x++;
            }
            else if(board[i][j] == 'O') {
                if(k>=5 && (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') || 
                   (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') || 
                   (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') || 
                   (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') || 
                   (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') || 
                   (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') || 
                   (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') || 
                   (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')) return "B";
                
                z++;
            }
            
            turn++;
        }
        
        if(x+z == 9) return "Draw";
        return "Pending";
    }
};