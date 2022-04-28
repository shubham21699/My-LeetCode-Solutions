class Solution {
    bool check(vector<vector<int>>& heights, int i, int j, int n, int m, vector<vector<bool>>& visited, int previousVal, int maxDiff) {
        
        if(i<0 || j<0 || i>=n || j>=m || visited[i][j]) return false;
        if(abs(heights[i][j] - previousVal) > maxDiff) return false;
        
        if(i==n-1 && j==m-1 && abs(heights[i][j] - previousVal) <= maxDiff) {
            return true;
        }
        
        visited[i][j] = true;
        
        return check(heights, i+1, j, n, m, visited, heights[i][j], maxDiff) ||
        check(heights, i, j+1, n, m, visited, heights[i][j], maxDiff) ||
        check(heights, i-1, j, n, m, visited, heights[i][j], maxDiff) ||
        check(heights, i, j-1, n, m, visited, heights[i][j], maxDiff);
        
    }

//     void check(vector<vector<int>>& heights, vector<int>& v, priority_queue<int, vector<int>, greater<int>>& pq, int maxDiff, int i, int j, int n, int m, vector<vector<bool>>& visited) {
        
//         if(i<0 || j<0 || i>=n || j>=m || visited[i][j]) return;
//         if(v.size() >= min(n, m) && abs(v.back() - heights[i][j]) > maxDiff) return;
        
//         if(!v.empty()) maxDiff = max(maxDiff, abs(v.back() - heights[i][j]));
        
//         if(i==n-1 && j==m-1) {
//             pq.push(maxDiff);
//             return;
//         }
        
//         visited[i][j] = true;
//         v.push_back(heights[i][j]);
        
//         check(heights, v, pq, maxDiff, i+1, j, n, m, visited);
//         check(heights, v, pq, maxDiff, i, j+1, n, m, visited);
//         check(heights, v, pq, maxDiff, i-1, j, n, m, visited);
//         check(heights, v, pq, maxDiff, i, j-1, n, m, visited);
        
//         v.pop_back();
//         visited[i][j] = false;
        
//     }
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();
        
        if(n == 1 && m == 1) return 0;
        if(n == 1) {
            int maxDiff = 0;
            for(int j=0 ; j<m-1 ; j++) maxDiff = max(maxDiff, abs(heights[0][j] - heights[0][j+1]));
            
            return maxDiff;
        }
        if(m == 1) {
            int maxDiff = 0;
            for(int i=0 ; i<n-1 ; i++) maxDiff = max(maxDiff, abs(heights[i][0] - heights[i+1][0]));
            
            return maxDiff;
        }
        
        int ans = -1;
        int low = 0;
        int high = 1e9;
        
        while(low <= high) {
            
            int mid = low + (high - low)/2;
            
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            
            if(check(heights, 0, 0, n, m, visited, heights[0][0], mid)) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
            
        }
        
        return ans;
        
        
//         // OR: Will give TLE
//         int maxDiff = 0;
//         vector<int> v;
//         priority_queue<int, vector<int>, greater<int>> pq;
//         vector<vector<bool>> visited(n, vector<bool>(m, false));
        
//         check(heights, v, pq, maxDiff, 0, 0, n, m, visited);
//         return pq.top();
    }
};