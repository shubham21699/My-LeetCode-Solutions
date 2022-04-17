class Solution {
    int check(int n, int position, vector<bool>& visited, int& count) {
        
        if(position > n) return count++;
        
        for(int i=1 ; i<=n ; i++) {
            if(!visited[i] && (i % position == 0 || position % i == 0)) {
                visited[i] = true;
                check(n, position+1, visited, count);
                visited[i] = false;
            }
        }
        
        return count;
    }
    
public:
    int countArrangement(int n) {
        
        if(n <= 3) return n;
        
        vector<bool> visited(n+1, false);
        int position = 1;
        int count = 0;
        return check(n, position, visited, count);
    }
};