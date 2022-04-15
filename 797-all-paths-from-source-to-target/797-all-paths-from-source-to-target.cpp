class Solution {
    void paths(vector<vector<int>>& graph, vector<vector<int>>& result, vector<int> v, int node, int n) {
        
        v.push_back(node);
        
        if(v.back() == n-1) {
            result.push_back(v);
            return;
        }
        
        for(int j=0 ; j<graph[node].size() ; j++) {
            paths(graph, result, v, graph[node][j], n);
        }
        
        v.pop_back();
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<vector<int>> result;
        vector<int> v;
        
        paths(graph, result, v, 0, n);
        return result;
    }
};