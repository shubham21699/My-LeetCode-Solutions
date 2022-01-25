class Solution {
    bool find(vector<vector<char> >& board, string word, int i, int j, int n, int m, int index) {
        
        if(i<0 || j<0 || i==n || j==m || word[index] != board[i][j]) return false;        
        if(index == word.length()-1) return true;
        
        board[i][j] = '*';
        
        bool result = find(board, word, i+1, j, n, m, index+1) || find(board, word, i, j+1, n, m, index+1) || find(board, word, i-1, j, n, m, index+1) || find(board, word, i, j-1, n, m, index+1);
        
        board[i][j] = word[index]; // Replace it back to its original value
        return result;
        
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                if(board[i][j] == word[0] && find(board, word, i, j, n, m, 0)) return true;
            }
        }
        
        return false;
        
    }
};