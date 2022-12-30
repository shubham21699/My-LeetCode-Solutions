class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        unordered_map<int, vector<pair<int, int>>> graph;
        
        for(int i=0 ; i<roads.size() ; i++) {
            graph[roads[i][0]].push_back({ roads[i][1], roads[i][2] });
            graph[roads[i][1]].push_back({ roads[i][0], roads[i][2] });
        }
        
        int score = INT_MAX;
        queue<int> q;
        q.push(1);
        vector<bool> visited(n+1, false);
        
        while(!q.empty()) {
            
            int currCity = q.front();
            q.pop();
            visited[currCity] = true;
            
            for(auto nextCity : graph[currCity]) {
                if(!visited[nextCity.first]) {
                    score = min(score, nextCity.second);
                    q.push(nextCity.first);
                }
            }
            
        }
        
        return score;
    }
};