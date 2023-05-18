class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        int m = edges.size();
        vector<int> incoming(n);
        
        for(int i=0 ; i<m ; i++) {
            incoming[edges[i][1]]++;
        }
        
        vector<int> result;
        for(int i=0 ; i<n ; i++) {
            if(incoming[i] == 0) result.push_back(i);
        }
        
        return result;
    }
};