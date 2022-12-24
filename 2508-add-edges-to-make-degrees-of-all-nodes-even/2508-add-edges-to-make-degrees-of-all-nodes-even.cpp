class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        
        unordered_map<int, unordered_set<int>> graph;
        vector<int> inDegree(n+1);
        
        for(int i=0 ; i<edges.size() ; i++) {
            graph[edges[i][0]].insert(edges[i][1]);
            graph[edges[i][1]].insert(edges[i][0]);
            inDegree[edges[i][0]]++;
            inDegree[edges[i][1]]++;
        }
        
        int countOddDegreeNodes = 0;
        vector<int> oddDegreeNodes;
        
        for(int i=1 ; i<=n ; i++) {
            if(inDegree[i] % 2 != 0) {
                countOddDegreeNodes++;
                oddDegreeNodes.push_back(i);
            }
            
            if(countOddDegreeNodes > 4) return false;
        }
        
        if(countOddDegreeNodes == 0) return true;
        
        if(countOddDegreeNodes == 2) {
            int a = oddDegreeNodes[0];
            int b = oddDegreeNodes[1];
            
            // If 'a' and 'b' nodes are not neighbours then they can be attached with each other with an edge.
            if(graph[a].find(b) == graph[a].end()) return true;
            else {
                // If two nodes are individually connected but can connect with some other even nodes and make all even degree
                for(int i=1 ; i<=n ; i++) {
                    if(graph[a].find(i) == graph[a].end() && graph[b].find(i) == graph[b].end()) return true;
                }
            }
            
            return false;
        }
        
        if(countOddDegreeNodes == 4) {
            int a = oddDegreeNodes[0];
            int b = oddDegreeNodes[1];
            int c = oddDegreeNodes[2];
            int d = oddDegreeNodes[3];
            
            if(graph[a].find(b) == graph[a].end() && graph[c].find(d) == graph[c].end()) return true;
            if(graph[a].find(c) == graph[a].end() && graph[b].find(d) == graph[b].end()) return true;
            if(graph[a].find(d) == graph[a].end() && graph[b].find(c) == graph[b].end()) return true;
            
            return false;
        }
        
        return false;
    }
};