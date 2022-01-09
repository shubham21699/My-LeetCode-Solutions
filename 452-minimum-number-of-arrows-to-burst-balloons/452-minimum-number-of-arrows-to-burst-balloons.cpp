class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        int n = points.size();
        int count = 0;
        
        sort(points.begin(), points.end(), [] (const vector<int> &a, const vector<int> &b)
          {
              return a[1] < b[1];
          });
        
        int target = points[0][1];
        
        for(int i=1 ; i<n ; i++) {
            if(target >= points[i][0] && target <= points[i][1]) continue;
            else {
                count++;
                target = points[i][1];
            }
        }
        
        return count+1;
        
    }
};