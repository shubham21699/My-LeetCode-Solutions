class Solution {
public:
    long long minCost = 0;
    
    long long dfs(vector<int> graph[], int city, vector<bool>& visited, int seats) {
        
        visited[city] = true;
        long long peopleCount = 1;
        
        for(auto nextCity : graph[city]) {
            if(!visited[nextCity]) {
                peopleCount += dfs(graph, nextCity, visited, seats);
            }
        }
        
        // If people are less than seats, then 1 car is enough
        if(peopleCount <= seats) minCost++;
        else {
            // Else we need more cars
            long long carsReq = ceil(peopleCount / (seats*1.0));
            minCost += carsReq;
        }
        
        return peopleCount;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        int n = roads.size();
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        vector<int> graph[n+1];
        
        for(int i=0 ; i<n ; i++) {
            graph[roads[i][0]].push_back(roads[i][1]);
            graph[roads[i][1]].push_back(roads[i][0]);
        }
        
        vector<bool> visited(n+1);
        visited[0] = true;
        
        for(auto city : graph[0]) {
            dfs(graph, city, visited, seats);
        }
        
        return minCost;
    }
};