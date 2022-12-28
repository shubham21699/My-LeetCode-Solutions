class Solution {
public:
    void getParent(vector<int> graph[], int node, vector<int>& parent, vector<bool>& visited) {
        
        visited[node] = true;
        
        for(auto child : graph[node]) {
            if(!visited[child]) {
                parent[child] = node;
                getParent(graph, child, parent, visited);
            }
        }
        
    }
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        
        int n = amount.size();
        vector<int> graph[n];
        
        for(int i=0 ; i<edges.size() ; i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> parent(n, -1);
        vector<bool> visited(n, false);
        getParent(graph, 0, parent, visited);
        
        int maxProfit = INT_MIN;
        
        queue<pair<int, int>> q;
        q.push({ 0, 0 });
        visited = vector<bool>(n, false);
        visited[0] = true;
        
        while(!q.empty()) {
            
            int size = q.size();
            
            while(size--) {
                
                int alice = q.front().first;
                int profit = q.front().second;
                q.pop();
                
                if(bob == alice) amount[alice] /= 2;
                bool isChildThere = false;
                
                for(auto child : graph[alice]) {
                    if(!visited[child]) {
                        q.push({ child, profit + amount[alice] });
                        visited[child] = true;
                        isChildThere = true;
                    }
                }
                
                // If no children then current node is Leaf node
                if(!isChildThere) maxProfit = max(maxProfit, profit + amount[alice]);
                
            }
            
            amount[bob] = 0;
            if(parent[bob] != -1) bob = parent[bob];
        }
        
        return maxProfit;
    }
};