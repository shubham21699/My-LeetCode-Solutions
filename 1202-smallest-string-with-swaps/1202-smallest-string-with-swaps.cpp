class Solution {
    void dfs(unordered_map<int, vector<int>>& graph, vector<bool>& visited, vector<int>& indexes, string& values, int index, string& s) {
        
        if(visited[index]) return;
        
        visited[index] = true;
        indexes.push_back(index);
        values += s[index];
        
        for(int x : graph[index]) {
            if(!visited[x]) {
                dfs(graph, visited, indexes, values, x, s);
            }
        }
        
    }
    
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int n = pairs.size();
        unordered_map<int, vector<int>> graph;
        
        for(auto p : pairs) {
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
        }
        
        vector<bool> visited(n, false);
        vector<int> indexes;
        string values = "";
        
        for(int i=0 ; i<n ; i++) {
            if(!visited[i]) {
                
                dfs(graph, visited, indexes, values, i, s);
                sort(indexes.begin(), indexes.end()); // Sort the indices in the same group.
                sort(values.begin(), values.end()); // Sort the characters in the same group.
                
                // Replace all the indices in the same group with the sorted charactes.
                for(int j=0 ; j<indexes.size() ; j++) {
                    s[indexes[j]] = values[j];
                }
                
                indexes.clear();
                values.clear();
                
            }
        }
        
        return s;
    }
};