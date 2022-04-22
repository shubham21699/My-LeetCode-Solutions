class Solution {
    double find(unordered_map<string, vector<pair<string, double>>> graph, unordered_set<string> visited, string start, string end) {
        
        if(graph.find(start) == graph.end() || graph.find(end) == graph.end()) return (double) -1.0;
        
        if(start == end) return 1.0; // If both are same, then their division result in 1.
        visited.insert(start); // Mark it as visited
        
        for(auto next : graph[start]) {
            if(visited.count(next.first) == 0) {
                double res = find(graph, visited, next.first, end);
                
                if(res != -1.0) return res * next.second;
            }
        }
         
        return -1.0;
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int n = equations.size();
        unordered_map<string, vector<pair<string, double>>> graph;
        
        for(int i=0 ; i<n ; i++) {
            graph[equations[i][0]].push_back({ equations[i][1], values[i] });
            graph[equations[i][1]].push_back({ equations[i][0], 1.0 / values[i] });
        }
        
        vector<double> result;
        
        for(auto q : queries) {
            unordered_set<string> visited; // Track previous visited nodes in order to avoid infinite loop.
            double ans = find(graph, visited, q[0], q[1]);
            result.push_back(ans);
        }
        
        return result;
    }
};