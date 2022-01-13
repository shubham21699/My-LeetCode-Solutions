class Solution {
    bool isSafe(vector<string>& v, int x, int y, int n) {
        
        for(int row=0 ; row<x ; row++) {
            if(v[row][y] == 'Q') return false;
        }
        
        for(int row=x-1, col=y-1 ; row>=0 && col>=0 ; row--, col--) {
            if(v[row][col] == 'Q') return false;
        }
        
        for(int row=x-1, col=y+1 ; row>=0 && col<n ; row--, col++) {
            if(v[row][col] == 'Q') return false;
        }
        
        return true;
    }
    
    void solve(vector<vector<string> >& board, vector<string>& v, int index, int n) {
        
        if(index >= n) {
            board.push_back(v);
            return;
        }
        
        for(int col=0 ; col<n ; col++) {
            if(isSafe(v, index, col, n)) {
                v[index][col] = 'Q';
                solve(board, v, index+1, n);
                v[index][col] = '.';
            }
        }
        
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        
        if(n == 1) return {{"Q"}};
        
        vector<vector<string> > board;
        if(n <= 3) return board;
        
        vector<string> v;
        
        for(int i=0 ; i<n ; i++) {
            string s = "";
            for(int j=0 ; j<n ; j++) {
                s += '.';
            }
            
            v.push_back(s);
        }
        
        solve(board, v, 0, n);
        
        return board;
    }
};