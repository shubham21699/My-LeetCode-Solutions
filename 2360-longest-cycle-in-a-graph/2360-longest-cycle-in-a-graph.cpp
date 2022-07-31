class Solution {
public:
    bool isCycle(vector<int> graph[], int node, vector<bool>& visited, vector<bool>& dfsVisited, int& len, int starting) {
    
        visited[node] = true;
        dfsVisited[node] = true;
        len++;

        for(auto n : graph[node]) {
            if(!visited[n]) {
                if(isCycle(graph, n, visited, dfsVisited, len, starting)) 
                    return true;
            }
            else if(dfsVisited[n] && n == starting) return true;
        }

        dfsVisited[node] = false;
        visited[node] = false;
        return false;
    }
    
    int longestCycle(vector<int>& edges) {
        
        int n = edges.size();
        vector<int> graph[n];
        
        for(int i=0 ; i<n ; i++) {
            if(edges[i] == -1) continue;
            else graph[i].push_back(edges[i]);
        }
        
        vector<bool> visited(n);
        vector<bool> dfsVisited(n);
        int res = -1;
        
        for(int i=0 ; i<n ; i++) {
            int len = 0;
            if(!visited[i] && isCycle(graph, i, visited, dfsVisited, len, i)) {
                res = max(res, len);
            }
        }

        return res;
        
    }
};