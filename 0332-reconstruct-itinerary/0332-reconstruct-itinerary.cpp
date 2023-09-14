class Solution {
public:
    void dfs(unordered_map<string, vector<string>>& graph, string curr, vector<string>& result) {
        
        while(graph[curr].size()) {
            string next = *graph[curr].begin();
            graph[curr].erase(graph[curr].begin());
            dfs(graph, next, result);
        }
        
        result.push_back(curr);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        int n = tickets.size();
        unordered_map<string, vector<string>> graph;
        
        for(int i=0 ; i<n ; i++) {
            graph[tickets[i][0]].push_back(tickets[i][1]);
            if(graph[tickets[i][0]].size() > 1) sort(graph[tickets[i][0]].begin(), graph[tickets[i][0]].end());
        }
        
        vector<string> result;
        
        dfs(graph, "JFK", result);
        
        reverse(result.begin(), result.end());
        return result;
    }
};