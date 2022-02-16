class Solution {
    struct hashFunction {
        size_t operator()(const pair<int , int> &x) const {
            return x.first ^ x.second;
        }
    };
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        
        unordered_set<pair<int, int>, hashFunction > s;
    
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                
                int live_neighbors = 0;
                if(i+1<n && board[i+1][j] == 1) live_neighbors++;
                if(j+1<m && board[i][j+1] == 1) live_neighbors++;
                if(i-1>=0 && board[i-1][j] == 1) live_neighbors++;
                if(j-1>=0 && board[i][j-1] == 1) live_neighbors++;
                if(i+1<n && j+1<m && board[i+1][j+1] == 1) live_neighbors++;
                if(i-1>=0 && j-1>=0 && board[i-1][j-1] == 1) live_neighbors++;
                if(i+1<n && j-1>=0 && board[i+1][j-1] == 1) live_neighbors++;
                if(i-1>=0 && j+1<m && board[i-1][j+1] == 1) live_neighbors++;
                
                if(board[i][j] == 1 && (live_neighbors < 2 || live_neighbors > 3)) s.insert({i, j});
                else if(board[i][j] == 0 && live_neighbors == 3) s.insert({i, j});
                
            }
        }
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                if(s.find({i, j}) != s.end()) {
                    if(board[i][j] == 1) board[i][j] = 0;
                    else if(board[i][j] == 0) board[i][j] = 1;
                }
            }
        }
        
    }
};