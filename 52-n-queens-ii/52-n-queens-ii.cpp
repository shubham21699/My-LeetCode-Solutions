class Solution {
    bool isSafe(vector<vector<int>>& chess, int n, int i, int j) {
        
        int k = j;
        for(int index=i ; index>=0 && k>=0; index--) {
            if(chess[index][k] == 1) return false;
            k--;
        }
        
        k = j;
        for(int index=i ; index>=0 && k<n ; index--) {
            if(chess[index][k] == 1) return false;
            k++;
        }
        
        for(int index=i ; index>=0 ; index--) {
            if(chess[index][j] == 1) return false;
        }
        
        return true;
    }
    
    int ways(vector<vector<int>>& chess, int n, int i, int j) {
        
        if(i >= n) return 1;
        if(j >= n) return 0;
        int count = 0;
        
        for(int col=0 ; col<n ; col++) {
            if(isSafe(chess, n, i, col)) {
                chess[i][col] = 1;
                count += ways(chess, n, i+1, col);
                chess[i][col] = 0;
            }
        }
        
        return count;
    }
    
public:
    int totalNQueens(int n) {
        
        vector<vector<int>> chess(n, vector<int>(n, 0));
        return ways(chess, n, 0, 0);
    }
};