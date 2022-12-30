class Solution {
public:
    /* First lets solve a simpler version of the problem 
    Assume all the nodes are connected.
    Lets run a BFS from every node in the graph and if at any point in the BFS we visit a node that is already
    visited and the abs(currectDepth - nodeDepth) != 1 we return -1 and we do that for every node in the graph.
    If any node returns -1 then there is no solution.
    
    Now for the actual problem
    We first need to get the number of connected components in the graph and for each component .
    We loop over it's nodes and try a BFS from evey one if any component doesn't have a solution we return -1.
    The total answer is the sum of all components groups count. */
    
    int parent[501];
    
    int root(int v) {
        return parent[v] < 0 ? v : (parent[v] = root(parent[v]));
    }
    
    void merge(int x, int y) {
        
        x = root(x);
        y = root(y);
        
        if (x == y) return;
        if (parent[x] > parent[y]) swap(x,y);
        
        parent[x] += parent[y];
        parent[y] = x;
    }
    
    int bfs(int source, unordered_map<int, vector<int>>& graph, int n) { 
        
        vector<int> visited(n , -1);
        visited[source] = 0;
        int depth = 0;
        queue<int> q;
        q.push(source);
        
        while(!q.empty()) {
            
            int size = q.size();
            
            while(size--) {
                
                auto curr = q.front();
                q.pop();
                
                for(auto next : graph[curr]) {
                    if(visited[next] == -1) {
                        visited[next] = depth + 1;
                        q.push(next);
                    } 
                    else if(abs(visited[next] - depth) != 1) return -1;
                }
                
            }
            
            depth++;
        }
        
        return depth;
    }
    
    int magnificentSets(int n, vector<vector<int>>& edges) {
        
        unordered_map<int, vector<int>> graph;
        memset(parent, -1, sizeof(parent));
        
        for(auto e : edges) {
            graph[e[0] - 1].push_back(e[1] - 1);
            graph[e[1] - 1].push_back(e[0] - 1);
            merge(e[0]-1, e[1]-1);
        }
        
        unordered_map<int, vector<int>> connectedComponents;
        
        for(int i=0 ; i<n ; i++) {
            connectedComponents[root(i)].push_back(i);
        }
        
        int totalNumberofGroup = 0;
        
        for(auto [val, nodes] : connectedComponents) {
            
           int componentGroups = -1; 
            
            for(auto node : nodes) {
                componentGroups = max(componentGroups, bfs(node, graph, n));
                
				if (componentGroups == -1) return -1;
            }
            
            totalNumberofGroup += componentGroups;
        }
        
        return totalNumberofGroup;
    } 
};