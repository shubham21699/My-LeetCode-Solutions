class UnionFind {
public:
    vector<int> parent, rank;
    int count;

    UnionFind(int n) : parent(n), rank(n), count(n) {
        
        for (int i=0 ; i<n ; i++) {
            parent[i] = i;
        }
        
    }

    int find(int x) {
        
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        
        return parent[x];
    }

    bool union_(int x, int y) {
        
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return false;
        }

        if (rank[rootX] < rank[rootY]) {
            swap(rootX, rootY);
        }

        parent[rootY] = rootX;

        if (rank[rootX] == rank[rootY]) {
            rank[rootX]++;
        }

        count--;

        return true;
    }
};

class Solution {
public:
    void dfs(int node, vector<int>& visited, vector<vector<int>>& graph) {
        
        visited[node] = 1;
        
        for(auto& child : graph[node]) {
            
            if(!visited[child]) {
                dfs(child, visited, graph);
            }
            
        }
    }
    
    bool isSimilar(string& x, string& y) {
        
        if(x == y) return true;
        
        int diff = 0;
        
        for(int i=0 ; i<x.length() ; i++) {
            if(x[i] != y[i]) diff++;
            if(diff > 2) return false;
        }
        
        return true;
    }
    
    int numSimilarGroups(vector<string>& strs) {
        
        int n = strs.size();
        vector<vector<int>> graph(n);
        
        for(int i=1 ; i<n ; i++) {
            for(int j=0 ; j<i ; j++) {
                
                if(isSimilar(strs[i], strs[j])){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
                
            }
        }
        
        int count = 0;
        vector<int> visited(n);
        
        for(int i=0 ; i<n ; i++) {
            if(!visited[i]) {
                dfs(i, visited, graph);
                count++;
            }
        }
        
        return count;
        
//         UnionFind uf(n);
//         int count = 0;
        
//         for(int i=0 ; i<n ; i++) {
//             for(int j=i+1 ; j<n ; j++) {
//                 if(isSimilar(strs[i], strs[j])) uf.union_(i, j);
//             }
//         }
        
//         return uf.count;
    }
};