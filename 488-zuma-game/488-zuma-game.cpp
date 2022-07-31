class Solution {
public:
    string updateBoard(string board) {
        
        int start = 0;
        int end = 0;
        int boardLen = board.length();
        
        while(start < boardLen) {
            
            while(end < boardLen && board[start] == board[end]) {
                end++; // Increment end pointer if consecutive balls are of same color.
            }
            
            // Here, end will point to the ball next to the consecutive balls of same color
            // such that number of balls of same color = end - start
            if(end - start >= 3) {
                
                string newBoard = board.substr(0, start) + board.substr(end);
                return updateBoard(newBoard);  // Recursively check if there are more groups in the new string
            }
            else {
                start = end;
            }
            
        }
        
        return board;
    }
    
    string serialize(vector<int>& freq) {
        
        string key = "";
        
        for(int i=0 ; i<freq.size() ; i++) {
            if(freq[i] > 0) {
                key += to_string((char) i + 'A') + to_string(freq[i]);
            }
        }
        
        return key;
    }
    
    int dfs(string board, vector<int>& freq, unordered_map<string, int>& cache) {
        
        string key = board + "#" + serialize(freq);
        
        if(cache.count(key)) return cache[key];
        
        int r = INT_MAX;
        
        // Base Case => We have removed all the balls from table.
        if(board.length() == 0) r = 0;
        else {
            
            for(int i=0 ; i<board.length() ; i++) { // try inserting a ball from hand at every position on row of balls.
                for(int j=0 ; j<freq.size() ; j++) { // try all the balls at every position.
                    
                    bool worthTrying = false;
                    
                    if(board[i] - 'A' == j) {
                        worthTrying = true;
                    }
                    else if(i > 0 && board[i] == board[i-1] && board[i] - 'A' != j) {
                        worthTrying = true;
                    }
                    
                    if(freq[j] > 0 && worthTrying) {
                        
                        board.insert(board.begin() + i, j + 'A');
                        freq[j]--; // Update the freq of ball.
                        
                        // Remove groups of 3 or more if possible.
                        string newStr = updateBoard(board);
                        
                        int steps = dfs(newStr, freq, cache);
                        
                        // Steps will be -1 if we can't remove all the balls during this combination.
                        if(steps != -1) {
                            r = min(r, steps + 1);
                        }
                        
                        freq[j]++; // Restore the frequency
                        board.erase(board.begin() + i); // Remove the ball fro this position to try next combination.
                        
                    }
                    
                }
            }
            
        }
        
        if(r == INT_MAX) r = -1; // If we can't remove all the balls.
        cache[key] = r;
        return r;
    }
    
    int findMinStep(string board, string hand) {
        
        int n = board.length();
        int m = hand.length();
        
        vector<int> freq(26, 0);
        for(int i=0 ; i<m ; i++) {
            freq[hand[i] - 'A']++;
        }
        
        unordered_map<string, int> cache;
        return dfs(board, freq, cache);
    }
};