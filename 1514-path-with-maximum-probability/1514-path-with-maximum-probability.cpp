class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        if(n == 1) return 0.0;
        vector<unordered_map<int, double>> graph(n);
        
        for(int i=0 ; i<edges.size() ; i++) {
            graph[edges[i][0]][edges[i][1]] = succProb[i];
            graph[edges[i][1]][edges[i][0]] = succProb[i];
        }
        
        vector<double> prob(n, 0.0);
        prob[start] = 1.0;
        
        queue<int> q;
        q.push(start);
        
        while(!q.empty()) {
            
            int curr = q.front();
            q.pop();
            
            for(auto x : graph[curr]) {
                
                int next = x.first;
                double probab = x.second;
                
                if(prob[curr] * probab > prob[next]) {
                    prob[next] = prob[curr] * probab;
                    q.push(next);
                }
                
            }
            
        }
        
        return prob[end];
    }
};