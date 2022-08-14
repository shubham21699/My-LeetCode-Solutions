class Solution {
public:
    int edgeScore(vector<int>& edges) {
        
        int n = edges.size();
        unordered_map<int, set<int>> graph;
        
        for(int i=0 ; i<n ; i++) {
            graph[edges[i]].insert(i);
        }
        
        vector<long long> scores(n, 0);
        
        for(int i=0 ; i<n ; i++) {
            
            long long score = 0;
            
            for(auto node : graph[i]) {
                score += node;
            }
            
            scores[i] = score;
        }
        
        int result = 0;
        long long maxScore = 0;
        
        for(int i=0 ; i<n ; i++) {
            if(maxScore < scores[i]) {
                maxScore = scores[i];
                result = i;
            }
        }
        
        return result;
    }
};