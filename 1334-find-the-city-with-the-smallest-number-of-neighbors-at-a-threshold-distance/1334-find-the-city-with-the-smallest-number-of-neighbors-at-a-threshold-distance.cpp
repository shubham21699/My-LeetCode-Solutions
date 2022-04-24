class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> distance(n, vector<int>(n, 10001));
        int result = 0;
        int smallest = n;
        
        for(auto e : edges) {
            distance[e[0]][e[1]] = e[2];
            distance[e[1]][e[0]] = e[2];
        }
        
        for(int i=0 ; i<n ; i++) {
            distance[i][i] = 0;
        }
        
        for(int k=0 ; k<n ; k++) {
            for(int i=0 ; i<n ; i++) {
                for(int j=0 ; j<n ; j++) {
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
        
        for(int i=0 ; i<n ; i++) {
            
            int count = 0;
            
            for(int j=0 ; j<n ; j++) {
                
                if(distance[i][j] <= distanceThreshold) 
                    count++;
                
            }
            
            if(count <= smallest) {
                result = i;
                smallest = count;
            }
            
        }
        
        return result;
    }
};