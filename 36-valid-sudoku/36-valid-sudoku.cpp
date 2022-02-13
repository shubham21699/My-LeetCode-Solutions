class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // Check for each column
        for(int i=0 ; i<9 ; i++) {
            unordered_set<char> s;
            for(int j=0 ; j<9 ; j++) {
                if(board[i][j] == '.') continue;
                if(s.find(board[i][j]) != s.end()) return false;
                s.insert(board[i][j]);
            }
        }
        
        // Check for each row
        for(int j=0 ; j<9 ; j++) {
            unordered_set<char> s;
            for(int i=0 ; i<9 ; i++) {
                if(board[i][j] == '.') continue;
                if(s.find(board[i][j]) != s.end()) return false;
                s.insert(board[i][j]);
            }
        }
        
        // Check for each sub-box
        for(int i=0 ; i<9 ; i+=3) {
            for(int j=0 ; j<9 ; j+=3) {
                unordered_set<char> s;
                for(int k=i ; k<i+3 ; k++) {
                    for(int l=j ; l<j+3 ; l++) {
                        if(board[k][l] == '.') continue;
                        if(s.find(board[k][l]) != s.end()) return false;
                        s.insert(board[k][l]);
                    } 
                }
            }
        }
        
        return true;
    }
};