class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        if(n == 1) return 0;
        unordered_map<int, vector<int>> graph;
        queue<int> leafNodes;
        
        for(int i=0 ; i<n ; i++) {
            if(i == headID) continue;
            if(informTime[i] == 0) leafNodes.push(i);
            graph[manager[i]].push_back(i);
        }
        
        // Using BFS Approach :
        queue<int> q;
        q.push(headID);
        int timeTaken = 0;
        
        while(!q.empty()) {
            
            int n = q.size();
            int time = 0;
            
            while(n--) {
            
                int currentEmpID = q.front();
                q.pop();
                for(auto x : graph[currentEmpID]) {
                    q.push(x);
                    informTime[x] += informTime[currentEmpID];
                }
                
            }
            
        }
        
        while(!leafNodes.empty()) {
            timeTaken = max(timeTaken, informTime[leafNodes.front()]);
            leafNodes.pop();
        }
        
        return timeTaken;
    }
};