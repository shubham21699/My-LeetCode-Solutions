class Solution {
public:
    int minSteps(vector<int>& arr, int i, int n, unordered_map<int, priority_queue<int>>& ind, unordered_map<int, bool> visited) {
        
        if(i >= n || i < 0) return n;
        if(visited.find(i) != visited.end()) return n;
        if(i == n-1) return 0;
        
        int steps = n;
        visited[i] = true;
        
        auto p = ind[arr[i]];
        
        while(!p.empty()) {
            
            int j = p.top();
            if(arr[i] == arr[j] && i < j && visited.find(j) == visited.end()) 
                steps = min(steps, 1 + minSteps(arr, j, n, ind, visited));
            
            p.pop();
            
        }
        
        steps = min({ steps, 1 + minSteps(arr, i+1, n, ind, visited), 1 + minSteps(arr, i-1, n, ind, visited) });
        
        visited.erase(i);
        return steps;
    }
    
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();
        if(n == 1) return 0;
        if(n == 2) return 1;
        
        unordered_map<int, vector<int>> ind;
        for(int i=0 ; i<n ; i++) {
            ind[arr[i]].push_back(i);
        }
        
        // BFS Approach:
        int steps = 0;
        vector<bool> visited(n);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()) {
            
            int k = q.size();
            
            while(k--) {
                
                int i = q.front();
                q.pop();
                
                if(i == n-1) return steps; // Reached to last index
                
                if(i+1 < n) ind[arr[i]].push_back(i+1);
                if(i-1 >= 0) ind[arr[i]].push_back(i-1);
                
                for(auto j : ind[arr[i]]) {
                    if(!visited[j]) {
                        q.push(j);
                        visited[j] = true;
                    }
                }
                
                ind[arr[i]].clear(); // To avoid later lookup of indices of arr[i]
            }
            
            steps++;
        }
        
        return steps;
        
        // // OR: Will give TLE
        // unordered_map<int, bool> visited;
        // return minSteps(arr, 0, n, ind, visited);
    }
};