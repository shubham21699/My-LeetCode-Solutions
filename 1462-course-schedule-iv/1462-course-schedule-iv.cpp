class Solution {
public:
    void dfs(unordered_map<int, set<int>>& graph, vector<bool>& visited, int curr, int preNode, unordered_map<int, set<int>>& mp) {
        
        visited[curr] = true;
        mp[curr].insert(preNode);
        
        for(auto node : graph[curr]) {
            if(!visited[node]) {
                dfs(graph, visited, node, preNode, mp);
            }
        }
        
    }
    
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        int n = prerequisites.size();
        int q = queries.size();
        unordered_map<int, set<int>> graph;
        
        for(int i=0 ; i<n ; i++) {
            graph[prerequisites[i][1]].insert(prerequisites[i][0]);
        }
        
        unordered_map<int, set<int>> mp;
        
        for(int i=0 ; i<numCourses ; i++) {
            vector<bool> visited(numCourses);
            dfs(graph, visited, i, i, mp);
        }
        
        vector<bool> res(q);
        
        for(int i=0 ; i<q ; i++) {
            if(mp[queries[i][0]].find(queries[i][1]) != mp[queries[i][0]].end()) {
                res[i] = true;
            }
        }
     
        return res;
    }
};