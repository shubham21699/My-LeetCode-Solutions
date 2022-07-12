class Solution {
    bool isPossible(vector<int>& matchsticks, int index, int n, vector<bool>& visited, int sum, int target, int k) {
        
        if(k == 1) return true;
        if(sum == target) return isPossible(matchsticks, 0, n, visited, 0, target, k-1);
        
        for(int i=index ; i<n ; i++) {
            if(visited[i] || sum + matchsticks[i] > target) continue;
            
            visited[i] = true;
            if(isPossible(matchsticks, i+1, n, visited, sum + matchsticks[i], target, k)) return true;
            visited[i] = false;
        }
        
        return false;
    }
    
public:
    bool makesquare(vector<int>& matchsticks) {
        
        int n = matchsticks.size();
        if(n < 4) return false;
        if(n == 4) return matchsticks[0] == matchsticks[1] && matchsticks[1] == matchsticks[2] && matchsticks[2] == matchsticks[3];
        
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(total % 4 != 0) return false;
        
        int len = total / 4;
        vector<bool> visited(n);
        return isPossible(matchsticks, 0, n, visited, 0, len, 4);
    }
};