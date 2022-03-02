class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        int n = points.size();
        if(n == 1 || k >= n) return points;
        
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, greater<pair<double, vector<int>>> > pq;
        
        for(int i=0 ; i<n ; i++) {
            double distance_from_origin = (sqrt(pow(points[i][0], 2) + pow(points[i][1], 2))) / 1.0;
            pq.push({ distance_from_origin, points[i] });
        }
        
        vector<vector<int>> result;
        
        while(!pq.empty() && k--) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        return result;
    }
};