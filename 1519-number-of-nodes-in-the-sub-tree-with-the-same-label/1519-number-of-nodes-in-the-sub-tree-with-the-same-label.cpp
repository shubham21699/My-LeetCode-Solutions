class Solution {
public:
    vector<int> countChars(unordered_map<int, vector<int>>& graph, int node, vector<bool>& visited, string& labels, vector<int>& result) {

        visited[node] = true;
        vector<int> counter(26);
        
        for(auto child : graph[node]) {
            if(!visited[child]) {
                vector<int> count = countChars(graph, child, visited, labels, result);
                for(int i=0 ; i<26 ; i++) {
                    counter[i] += count[i];
                }
            }
        }
        
        result[node] = ++counter[labels[node]-'a'];
        return counter;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        unordered_map<int, vector<int>> graph;
        
        for(auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        vector<bool> visited(n);
        vector<int> result(n);
        countChars(graph, 0, visited, labels, result);
        
        return result;
    }
};