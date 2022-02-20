class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        if(n == 1) return 1;
        
        sort(intervals.begin(), intervals.end());
        
        int a = intervals[0][0];
        int b = intervals[0][1];
        int count_of_non_covered_intervals = 1;
        
        for(int i=1 ; i<n ; i++) {
            int c = intervals[i][0];
            int d = intervals[i][1];
            
            if(a < c && b < d) {
                count_of_non_covered_intervals++;
            }
            
            if(d > b) {
                a = c;
                b = d;
            }
        }
        
        return count_of_non_covered_intervals;
    }
};