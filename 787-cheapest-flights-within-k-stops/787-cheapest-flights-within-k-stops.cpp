class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        int m = flights.size();
        unordered_map<int, vector<pair<int, int>>> graph;
        
        for(int i=0 ; i<m ; i++) {
            graph[flights[i][0]].push_back({ flights[i][1], flights[i][2] });
        }
        
        queue<pair<int, int>> q;
        q.push({ src, 0 });
        vector<int> distance(n, INT_MAX);
        int cost = INT_MAX;
        int stops = 0;
        
        while(!q.empty() && stops <= k) {
            
            int n = q.size();
            
            while(n--) {
            
                auto current = q.front();
                q.pop();
                
                if(distance[current.first] < current.second) continue;
                distance[current.first] = current.second;
                
                for(auto x : graph[current.first]) {

                    if(current.second + x.second > cost) continue;
                    if(x.first == dst) cost = min(cost, current.second + x.second);
                    q.push({ x.first, current.second + x.second });

                }
            }
            
            stops++;
            
        }
        
        return cost == INT_MAX ? -1 : cost;
    }
};