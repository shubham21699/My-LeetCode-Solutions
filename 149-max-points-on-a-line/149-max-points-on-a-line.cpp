class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        if(n <= 2) return n;
        
        int result = 0;
        
        for(int i=0 ; i<n-1 ; i++) {
            unordered_map<double, int> m;
            int numVerticals = 1;
            int local = 1;
            int duplicates = 0;
            
            for(int j=i+1 ; j<n ; j++) {
                if(points[i][0] == points[j][0]) { // Special Case
                    if(points[i][1] == points[j][1]) { // Duplicates
                        duplicates++;
                    }
                    else // Verticals
                        numVerticals++;
                }
                else {
                    double slope = (points[i][1] - points[j][1]) * 1.0 / (points[i][0] - points[j][0]);
                    m[slope] == 0 ? m[slope] = 2 : m[slope]++;
                    local = max(local, m[slope]);
                }
                
                local = max(local + duplicates, numVerticals + duplicates);
                result = max(result, local);
            }
        }
        
        return result;
    }
};