class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        
        int m = flowers.size();
        int n = people.size();
        vector<int> result(n);
        
        vector<int> start(m), end(m);
        
        for(int i=0 ; i<m ; i++) {
            start[i] = flowers[i][0];
            end[i] = flowers[i][1];
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        for(int i=0 ; i<n ; i++) {
            int startPt = upper_bound(start.begin(), start.end(), people[i]) - start.begin();
            int endPt = lower_bound(end.begin(), end.end(), people[i]) - end.begin();
            
            result[i] = startPt - endPt;
        }
        
        return result;
    }
};