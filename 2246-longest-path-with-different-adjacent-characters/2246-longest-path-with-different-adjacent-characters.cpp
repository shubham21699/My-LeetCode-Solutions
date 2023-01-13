class Solution {
public:
    int LP(unordered_map<int, vector<int>>& graph, int node, string& s, int& result) {
        
        /*
        dfs(i) return the the longest path starting at the node i.
        dfs on each node i, and for each node i, we iterate on all its children,
        and find all the path startint at the node i.
        The 2 longest path can make up the longest path in subtree of node i, we update the global result
        and return the longest path length as result for dfs. */
        
        int big1 = 0, big2 = 0;
        
        for(auto child : graph[node]) {
            int length = LP(graph, child, s, result);
            
            if(s[child] == s[node]) continue;
            if(length > big2) big2 = length;
            if(big2 > big1) swap(big1, big2);
        }
        
        result = max(result, big1 + big2 + 1);
        return big1+1;
    }
    
    int longestPath(vector<int>& parent, string s) {
        
        int n = parent.size();
        unordered_map<int, vector<int>> graph;
        
        for(int i=1 ; i<n ; i++) {
            graph[parent[i]].push_back(i);
        }
        
        int result = 0;
        LP(graph, 0, s, result);
        
        return result;
    }
};