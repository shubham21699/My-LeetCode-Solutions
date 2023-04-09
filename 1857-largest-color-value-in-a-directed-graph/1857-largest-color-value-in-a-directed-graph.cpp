class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        int n = colors.length();
        int m = edges.size();
        
        unordered_map<int, vector<int>> graph;
        vector<int> inDegree(n);
        
        for(int i=0 ; i<m ; i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            inDegree[edges[i][1]]++;
        }
        
        queue<int> q;
        vector<vector<int>> count(n, vector<int>(26));
        
        for(int i=0 ; i<n ; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
                count[i][colors[i]-'a'] = 1;
            }
        }
        
        int largestVal = 0;
        int seen = 0;
        
        while(!q.empty()) {
            
            int curr = q.front();
            q.pop();
            int val = *max_element(count[curr].begin(), count[curr].end());
            largestVal = max(largestVal, val);
            seen++;
            
            for(auto next : graph[curr]) {
                for(int i=0 ; i<26 ; i++) {
                    count[next][i] = max(count[next][i], count[curr][i] + (i == colors[next]-'a'));
                }
                
                if(--inDegree[next] == 0) q.push(next);
            }
            
        }
        
        return seen < n ? -1 : largestVal;
    }
};