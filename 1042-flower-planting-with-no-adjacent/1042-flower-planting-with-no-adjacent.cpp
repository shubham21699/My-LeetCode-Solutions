class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
        vector<int> result(n, 0);
        vector<int> graph[n+1];
        
        for(int i=0 ; i<paths.size() ; i++) {
            graph[paths[i][0]].push_back(paths[i][1]);
            graph[paths[i][1]].push_back(paths[i][0]);
        }
        
        result[0] = 1;
        
        for(int current_node=2 ; current_node<=n ; current_node++) {
            
            unordered_map<int, int> m;
            m[1] = 1;
            m[2] = 1;
            m[3] = 1;
            m[4] = 1;
            
            for(auto node : graph[current_node]) {
                if(result[node-1] == 1) {
                    m[1] = 0;
                }
                else if(result[node-1] == 2) {
                    m[2] = 0;
                }
                else if(result[node-1] == 3) {
                    m[3] = 0;
                }
                else if(result[node-1] == 4) {
                    m[4] = 0;
                }
            }
            
            if(m[1] == 1) result[current_node-1] = 1;
            else if(m[2] == 1) result[current_node-1] = 2;
            else if(m[3] == 1) result[current_node-1] = 3;
            else if(m[4] == 1) result[current_node-1] = 4;
            
        }
        
        return result;
    }
};