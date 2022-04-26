class Solution {
    int find(vector<int>& parent, int point) {
        
        if(parent[point] == point) return point;
        return find(parent, parent[parent[point]]);
        
    }
    
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > minCost;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=i+1 ; j<n ; j++) {
                
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                minCost.push(make_pair( dist, make_pair(i, j) ));
                
            }
        }
        
        int noOfEdges = n-1;
        int cost = 0;
        
        while(noOfEdges > 0) {
            
            auto minCostPoint = minCost.top();
            minCost.pop();
            
            int p1 = find(parent, minCostPoint.second.first);
            int p2 = find(parent, minCostPoint.second.second);
            
            if(p1 != p2) {
                cost += minCostPoint.first;
                parent[p1] = p2;
                noOfEdges--;
            }
            
        }
        
        return cost;
    }
};